inherit ROOM;

void create()
{
        set("short", "���Ҹ�");
        set("long",@LONG
����������������ǰ�����㻹Ըʱ��Ϣ�ĵط�������̴��¯��
��齰�����һӦ��ȫ���徲֮����Ȼ͸��һ˿����֮��
LONG);
        set("no_fight",1);
        set("sleep_room", 1);
        set("exits", ([
		"south": __DIR__"men2",
        ]));
        set("coor/x",-360);
  set("coor/y",-310);
   set("coor/z",20);
   setup();
}
