//by xiaoyao

inherit ROOM;
void create()
{
        set("short","�ּ��");
        set("long",@LONG
������һ���ּ�С���������������ѡ����������������ɽ��
����ͨ�򸣽����ݡ�
LONG);
        set("objects", ([
           __DIR__"npc/zhang": 1,
           __DIR__"npc/zhangkang": 1,
        ]));
        set("outdoors", "��ɽ");
        set("exits",([ /* sizeof() == 1 */
            "west" : __DIR__"dongmen",
            "east" : __DIR__"road9",
        ]));
        set("coor/x",50);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}


