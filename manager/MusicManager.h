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
    void Pause();
    void Stop();

    void getTotalMusicDuration(int *minute, int *seconde);
    void getTotalMusicDuration(QString *duration);
    void getTotalMusicDuration(qint64 *duration);

    qint64 getTimeElapsed();

    static MusicManager *getInstance();
    static void deleteInstance();
public slots:
    void changeVolume(int volume);
    void changePositionMusic(int newTime);
private slots:
    void timeChangedSlot(qint64 timeElapsed);
    void currentSourceChangedSlot(Phonon::MediaSource mediasource);
    void MusicDurationSlot(qint64 newTotalTime);
signals:
    void timeChanged(qint64 secondeElapsed);
    void timeChanged(QString timeElapsed);
    void currentSourceChanged(QString sourceName);
    void totalTimeChanged();

private:
    QString                             m_currentMusicPath;
    static MusicManager                 *s_musicMgr;
    Phonon::AudioOutput                 *m_AudioOutput;
    Phonon::MediaObject                 *m_Media;
    int                                 m_currentMinElapsed;
    int                                 m_currentSecElapsed;
    int                                 m_currentMinTotal;
    int                                 m_currentSecTotal;
    int                                 m_currentDurationInSeconde;

    qint64                              m_time;
};


#endif // MUSICMANAGER_H

