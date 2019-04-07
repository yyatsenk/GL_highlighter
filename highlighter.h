#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class SearchHighLight : public QSyntaxHighlighter
{
    Q_OBJECT
    using BaseClass = QSyntaxHighlighter;
public:
    explicit SearchHighLight(QTextDocument* parent = nullptr);

    void searchText(const QString& text, const QString& words_to_high);

protected:
    virtual void highlightBlock(const QString &text) override;

private:
    QRegularExpression pattern; //rgexp what to highlight
    QTextCharFormat format;   //style of highlighting
};


#endif //HIGHLIGHTER_H
