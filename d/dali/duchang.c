inherit ROOM;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
�����Ǵ���ĳ��Ĵ��ã�������ͽ���Ű��ӣ���ͷ�󺹵������ƾţ�һЩ
�����Ա߿��ţ������������ֲ����ߵ��ˡ�ǽ�Ϲ���һ������(paizi)��
LONG
	);

	set("item_desc", ([
	      "paizi" : "��¥�Ĺ��������ڲ��Խ׶Ρ�\n",
	]));
	set("exits", ([
              "south" : __DIR__"beijie5",
	]));
        set("objects", ([
                __DIR__"npc/duke" : 2,
        ]));
	set("coor/x",-290);
  set("coor/y",-370);
   set("coor/z",-20);
   set("coor/x",-290);
  set("coor/y",-370);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/duchang",1);
      }
}

int valid_leave(object me, string dir)
{
        if (dir == "up" && this_player()->query("age")<18)
                return notify_fail("Сë���������Ϲ�պ�ʲô?!\n");
        return ::valid_leave(me, dir);
}
