 //milin.c by zly

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",
"������������û��·�ˣ�ͻȻ��������������������ԭ��������
���������ѡ�\n"
        );
        set("outdoors", "��ɽ");
        set("exits", ([
            "southwest" : __DIR__"xiaolu3",
        ]));
        set("objects",([
                __DIR__"npc/shanzei" : 2,
        ]));

        set("coor/x",10);
  set("coor/y",-460);
   set("coor/z",20);
   setup();
}

