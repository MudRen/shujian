 // /u/beyond/hz/yxsdong.c ��ϼ����
 
inherit ROOM;
void create()
{
 set("short","ʯ�ݶ�");
        set("long", @LONG
��ϼ���������ж��������ߴ�����ʯ�ݶ��߳����ݣ�������ж�����
��������ͨ���⡣�������޺����ʮ������������ɽ´һ��������Ƭ��
��ǰͥԺ�������𻨣�������ʱ���͹�ʥ�ء�
LONG
        );
        set("exits", ([
"southeast" : __DIR__"yxsdong1",
"northwest" : __DIR__"feilaifeng",
]));
        setup();
}
