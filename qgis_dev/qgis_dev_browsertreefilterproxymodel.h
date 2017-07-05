#ifndef QGIS_DEV_BROWSERTREEFILTERPROXYMODEL_H
#define QGIS_DEV_BROWSERTREEFILTERPROXYMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>
#include <QRegExp>
#include <QVector>

#include <qgsbrowsermodel.h>


class qgis_dev_browserTreeFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    qgis_dev_browserTreeFilterProxyModel( QObject *parent );
    ~qgis_dev_browserTreeFilterProxyModel();

    void setBrowserModel( QgsBrowserModel* model );
    void setFilterSyntax( const QString& syntax );
    void setFilter( const QString& filter );
    void setCaseSensitive( bool caseSensitive );
    void updateFilter();

protected:
    QgsBrowserModel* m_model;
    QString m_filter; // �������ַ���
    QVector<QRegExp> m_reList; // �������б��� "|" ���ŷָ�
    QString m_patternSyntax;
    Qt::CaseSensitivity m_caseSensitivity;

    bool filterAcceptsString( const QString& value ) const;
    bool filterAcceptsRow( int sourceRow, const QModelIndex &sourceParent ) const override;
    bool filterAcceptsAncestor( const QModelIndex &sourceIndex ) const;
    bool filterAcceptsDescendant( const QModelIndex &sourceIndex ) const;
    bool filterAcceptsItem( const QModelIndex &sourceIndex ) const;

};

#endif // QGIS_DEV_BROWSERTREEFILTERPROXYMODEL_H
