// /u/beyond/hz/qsddao3.c ��ʯ���
 
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
����СϪ����������Եľ��Ƿ����塣����������������ơ��θ�����
ʯ�񼸰����Ƿ�Ҳΰݵ���ʥ�ı��ء����Ϸ���һ����·��
LONG
        );
set("objects",([
__DIR__"npc/you" : 2,
]));
        set("exits", ([
"southeast" : "/d/thd/niujia/road",
"west" : __DIR__"lingyinsi",
"northwest" : __DIR__"qsddao2",
            "east" : __DIR__"feilaifeng",            
]));
        set("coor/x",50);
  set("coor/y",-320);
   set("coor/z",0);
   setup();
}
