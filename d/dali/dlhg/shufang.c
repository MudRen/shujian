inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "�鷿");
	set("long", @LONG
�����Ǵ���ʹ����鷿��ֻ��������ǵ������ľ�壬��ɽˮ�������
ë���ܣ��򼯽����򲩹ţ��������٣����ֻ����������ֵ��Σ��������Ƕ
���ġ������۾����������������ۡ���ǽ����һ����ܣ�jia)������ϰ��Ų�
�ٵ��顣
LONG
	);

	set("exits", ([
		"west" : __DIR__"huating",
	]));
	set("item_desc", ([
		"jia":"����һ����ɫ�������ܡ�\n",      
	]));

	set("coor/x",-300);
  set("coor/y",-420);
   set("coor/z",-20);
   setup();
}

void init()
{
        add_action("do_fan", "fan");
}

int do_fan(string arg)
{
        object me;
	object ob;
	me = this_player();
	if( !arg || arg!="jia" || !me->query_temp("fan"))
           return notify_fail("û���ҷ�ʲô��\n"); 
        if ( me->query_temp("book") < 4){
          me->add("jingli", -30);
        if (random(10) > 3){
	switch  (random(7)){
	case 0: ob = new(__DIR__"obj/book1"); break;
	case 1: ob = new(__DIR__"obj/book2"); break;
	case 2: ob = new(__DIR__"obj/book3"); break;
	case 3: ob = new(__DIR__"obj/book4"); break;
	case 4: ob = new(__DIR__"obj/book5"); break;
	case 5: ob = new(__DIR__"obj/book6"); break;
	case 6: ob = new(__DIR__"obj/book7"); break;
	case 7: ob = new(__DIR__"obj/book8"); break;
	}
          ob->set_temp("find",me->query("id"));
	  ob->move(this_player());
          message_vision(HIY "$N�Ѿ����ۣ����ڴ�������ҵ�һ���飡\n"NOR, me); 
          me->add_temp("book", 1);
	  }
	else{
	  message_vision("$N���˰��죬���ʲôҲû�ҵ���\n", me); 
	  }
          }
	else{
          return notify_fail("���Ѿ��ù����ˣ���ô�����ã�\n");
	}
     return 1;
}
