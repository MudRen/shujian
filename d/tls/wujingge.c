inherit ROOM;

void create()
{
        set("short", "�޾���");
        set("long",@LONG
����������������Ů��ǰ�����㻹Ըʱ��Ϣ�ĵط�������̴��
��¯����齰�����һӦ��ȫ���徲֮����Ȼ͸��һ˿����֮��
LONG);
        set("sleep_room", "1");
        set("no_fight", "1");
        set("exits", ([
		"south": __DIR__"men1",    			
        ]));
        set("coor/x",-340);
  set("coor/y",-310);
   set("coor/z",30);
   setup();
}
