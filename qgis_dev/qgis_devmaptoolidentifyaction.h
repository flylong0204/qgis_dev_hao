#ifndef QGIS_DEVMAPTOOLIDENTIFYACTION_H
#define QGIS_DEVMAPTOOLIDENTIFYACTION_H

#include <QObject>
#include <QMouseEvent>

#include <qgsmaptoolidentify.h>

//! ����ʵ������ʶ�𹤾�
class qgis_devMapToolIdentifyAction : public QgsMapToolIdentify
{
    Q_OBJECT

public:
    qgis_devMapToolIdentifyAction( QgsMapCanvas * canvas );
    ~qgis_devMapToolIdentifyAction();

    //! ��д�����ͷ��¼�
    virtual void canvasReleaseEvent( QMouseEvent * e );

};

#endif // QGIS_DEVMAPTOOLIDENTIFYACTION_H
