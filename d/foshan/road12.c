// by xiaoyao

inherit ROOM;
void create()
{
        set("short","�ּ��");
        set("long",@LONG
������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ������
�棬��λ��·Ҫʮ��С�ġ�
LONG);
        set("objects", ([
           __DIR__"npc/snake": 1,
        ]));
        set("outdoors", "��ɽ");
        set("exits",([ /* sizeof() == 1 */
            "northwest" : __DIR__"road10",
        ]));
        set("coor/x",80);
  set("coor/y",-540);
   set("coor/z",0);
   setup();
}


