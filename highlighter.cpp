#include "highlighter.h"

#include <QTextCharFormat>

SearchHighLight::SearchHighLight(QTextDocument* parent) : BaseClass(parent)
{
    //set style
    format.setBackground(Qt::green);
    format.setFontItalic(1);
}

void SearchHighLight::highlightBlock(const QString& text)
{
    QRegularExpressionMatchIterator matchIterator = pattern.globalMatch(text);

    while (matchIterator.hasNext())  //highlighting process
    {
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), format);
    }
}

void SearchHighLight::searchText(const QString& text, const QString& words_to_high)
{
    QStringList     words = words_to_high.split(QRegExp("(\\ |\\t)"));
    QString         res_regexp("(?:");
    int             max_len = 0;

    for(QString &word: words)
    {
        if (text.contains(word) && word.length() >= max_len
            && !word.contains(QRegExp("[$&+,:;=?@#|'<>.-^*()%!]"))) // regExp special symbols in text is not maintained
            max_len = word.length();
    }
    for(QString &word: words)
    {
        if (word.length() == max_len)
            res_regexp += word + "|";
    }
    res_regexp[res_regexp.length() - 1] = ')';
    pattern = QRegularExpression(res_regexp);
    rehighlight();
}
