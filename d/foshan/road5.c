//road5.c by XiaoYao

inherit ROOM;
void create()
{
        set("short","�ּ��");
        set("long",@LONG
������һ���ּ�С���������������ѡ������ǹ����ˡ�����ɽ
��ï�ܣ�������棬��λ��·Ҫʮ��С�ġ�
LONG);
        set("objects", ([
           __DIR__"npc/bee": 1,
        ]));
        set("outdoors", "��ɽ");
        set("exits",([ /* sizeof() == 1 */
            "west"      : __DIR__"road6",
            "northeast" : __DIR__"road4",
        ]));
        set("coor/x",-80);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}


