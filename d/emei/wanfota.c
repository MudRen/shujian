// wanfota.c
// �����
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long",@long
�����������ϵ�������ˣ����ڹ����źܶ���λ��
long);
	set("exits",([
	 "out" : __DIR__"wanfoding",
]));
	setup();
}

void reset()
{
	set("count", 1);
	::reset();
}

void init()
{
	add_action("do_ketou", "ketou");
	add_action("do_ketou", "�ݼ�");
}             

int do_ketou()
{
	object me = this_player();
	object ob = this_object();
	object ring;

	if ( !me->query_temp("marks/pass_yitian") ) return 0;
       me->receive_damage("jingli", 30);
	if ( me->query_temp("ketou") >= random( 60 ) + 1 ) {
		if ( query("count") > 0 && ring = unew(__DIR__"obj/ring")) {
			ring->move(ob);
			message("vision","ֻ��������һ�������������һֻ" +
				"��ָ����\n",me);
			me->delete_temp("ketou",1);
                        me->set_temp("marks/get_ring",1);
			add("count", -1);
			return 1;
		}
		else {
			message("vision","�㲻�������������ƺ��ѱ��򿪹���\n",
				me);
			me->delete_temp("ketou");
			return 1;
		}
	}
	else {
		me->add_temp("ketou", 1);
		message_vision("$N����������������ǰ���˸���ͷ��\n", me);
		return 1;
	}
}	
