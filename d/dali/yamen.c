// By River 98/12/
inherit ROOM;

void create()
{
	set("short", "����ǰ��");
	set("long", @LONG
�����Ǵ������Ҫ���õ�ǰ�����˴����Ա�����������֮�������ò���
�ܴ�װ�����أ����������־���ʿ���֡�����������ڣ��������������һ
�ţ�ͨ���������Ե�˾�á�
LONG
	);        
	set("exits", ([
           "south" : __DIR__"beijie1",
           "north" : __DIR__"sikong",
           "west" : __DIR__"sima",
           "east" : __DIR__"situ",
	]));

        set("objects", ([
              __DIR__"npc/bing" : 2,
              __DIR__"npc/wujiang" : 1,
        ]));

	set("coor/x",-330);
  set("coor/y",-370);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
        mapping fam;
        fam = (mapping)me->query("family");
        if ( (!fam || fam["family_name"] != "����" )
         && dir != "south" 
         && objectp(present("dali guanbing", environment(me))))
          return notify_fail("����ٱ���ס�㣬˵���������ڲ������������\n");
        if ( (!fam || fam["family_name"] != "����" )
         && dir != "south" 
         && objectp(present("dali wujiang", environment(me))))
          return notify_fail("�����佫��ס�㣬˵���������ڲ������������\n");
        return ::valid_leave(me, dir);
}
