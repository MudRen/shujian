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
           __DIR__"obj/hua2": 1,
        ]));
        set("outdoors", "��ɽ");
        set("exits",([ /* sizeof() == 1 */
            "west" : __DIR__"road8",
            "east" : __DIR__"road10",
        ]));
        set("coor/x",60);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}


