 // /u/beyond/hz/yxsdong1.c ��ϼ����
 
inherit ROOM;
void create()
{
        set("short","ˮ�ֶ�");
        set("long", @LONG
ˮ�ֶ��������������ˮ��ѭ�Ű�͹��ƽ��ˮ��ǰ����������������
���������������֡����������߾͵�����ϼ����
LONG
        );
set("objects",([
__DIR__"npc/jian-ke" : 1,
]));
        set("exits", ([
            "west" : __DIR__"yxsdong2",
            "northwest" : __DIR__"yxsdong",
]));
        setup();
}
