#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <QString>
#include <QObject>
#include <QDebug>
#include <Phonon/Phonon>

class MusicManager : public QObject
{
    Q_OBJECT
private:
    MusicManager(QObject *parent = 0);
    ~MusicManager() {}
public:
    void setMusicPath(QString path);
    QString getMusicPath();
    void Play();
    void Play(QString path);
    void Pause();
    void Stop();

    static MusicManager *getInstance();
    static void deleteInstance();
private slots:
    void timeChanged(qint64 timeElapsed);
    void currentSourceChangedSlot(Phonon::MediaSource mediasource);
signals:
    void currentSourceChanged(QString sourceName);

private:
    QString                             m_currentMusicPath;
    static MusicManager                 *s_musicMgr;
    Phonon::AudioOutput                 *m_AudioOutput;
    Phonon::MediaObject                 *m_Media;

    qint64                             m_time;
};


#endif // MUSICMANAGER_H

