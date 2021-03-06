#ifndef SINGLE_APPLICATION_H
#define SINGLE_APPLICATION_H

#include <QString>

// Change this to inherit from QGuiApplication or QCoreApplication
#ifndef QAPPLICATION_CLASS
  #define QAPPLICATION_CLASS QCoreApplication
#endif

#define  QUOTE(C) #C
#define  INCLUDE_FILE(C) QUOTE(C)
#include INCLUDE_FILE(QAPPLICATION_CLASS)

class SingleApplicationPrivate;

/**
 * @brief The SingleApplication class handles multipe instances of the same Application
 * @see QApplication
 */
class SingleApplication : public QAPPLICATION_CLASS
{
  Q_OBJECT
public:
  explicit SingleApplication(int&, char **, const QString &instanceRunningMessage);
  ~SingleApplication();

signals:
  void showUp();

private slots:
  void slotConnectionEstablished();

private:
  SingleApplicationPrivate *d_ptr;

  void printInstanceRunningMessage() const;
  QString m_instanceRunningMessage;
};

#endif // SINGLE_APPLICATION_H
