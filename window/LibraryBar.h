#ifndef LIBRARYBAR_H
#define LIBRARYBAR_H

#include <QFrame>
#include <QPushButton>
#include <QResizeEvent>
#include <QDebug>

class LibraryBar : public QFrame
{
    Q_OBJECT
public:
    LibraryBar(QWidget *parent = 0);
    ~LibraryBar();
    void createMusicBar();
    void resizeEvent(QResizeEvent *e);

signals:
    void musicBarItemSelected(QString itemName);

private slots:
    void musicBarItemSelectedSlot();
    void show2DViewSlot();
    void show3DViewSlot();

private:
    void createConnexionBtwSignalSlot();
    void deleteButton();

private:
    QPushButton                 *m_Artist;
    QPushButton                 *m_Album;
    QPushButton                 *m_Genre;
    QPushButton                 *m_2DViewButton;
    QPushButton                 *m_3DViewButton;


};

#endif // LIBRARYBAR_H
