//zumiao.c by zly

inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long",
"�����Ƿ�ɽ��������ʤ�ż�֮һ��ɽ�������￴���������֣���
˵����ķ�����飬�ܶ�����˶��������ˣ��������������ƣ�����
��ʢ��\n"
        );
        set("exits", ([
            "southeast" : __DIR__"xiaolu1",
        ]));
        set("objects",([
            __DIR__"npc/man" : 1,
        ]));

        set("no_clean_up", 0);
        set("coor/x",-10);
  set("coor/y",-480);
   set("coor/z",0);
   setup();
}

