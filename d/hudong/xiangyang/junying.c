inherit ROOM;

void create()
{
        set("short", "�ɹž�Ӫ");
        set("long", @LONG
�������ɹŹ�����������ʱ��Ӫ��ʱʱ��ʿ������Ѳ�ߡ�
�����ϱ��ܵ���������
LONG
        );
        set("xyjob", 1);
        set("outdoors", "����");
        set("objects", ([
                __DIR__"npc/weishi" : 3,
        ]));

        set("exits", ([
		"southwest" : __DIR__"outnroad2",
                "enter" : __DIR__"yingzhang",
        ]));

	setup();
}
int valid_leave(object me, string dir)
{
      if ((dir == "enter") 
      && (me->query_temp("xyjob/xy_defend")) 
      && (present("weishi", this_object())))
      return notify_fail("�㻹����ɱ���ſڵ���ʿ��˵�ɡ�\n");
      return ::valid_leave(me, dir);
}
