 // /u/beyond/hz/yxsdong2.c ��ϼ����
 
inherit ROOM;
void create()
{
        set("short","��ϼ��");
        set("long", @LONG
��ϼ����ʯ���Ͽ���������δ���ʯ�������������������Զ�������
������δ��ġ��������͡���������������Ϊ������
LONG
        );
        set("exits", ([
"southeast" : __DIR__"longjing",
           "east" : __DIR__"yxsdong1",
]));
        setup();
}
