//  antirobot1.c
//  By snowman@SJ 12/06/2000

#include <ansi.h>

inherit NPC;
string ans=" ";
string str = "���� answer �ش������ϵ���Ʒ��";
string *numbers = ({
({ "��","��","��","��","��","��","��","��","��" }),
({ "��","��","��","��","��","��","��","��","��" }),
({ "��","��","��","��","��","��","��","��","��" }),
({ "��","��","��","��","��","��","��","��","��" }),
({ "��","��","��","��","��","��","��","��","��" }),
({ "һ","��","��","��","��","��","��","��","��" }),
({ "1.","2.","3.","4.","5.","6.","7.","8.","9." }),
({ "(1)","(2)","(3)","(4)","(5)","(6)","(7)","(8)","(9)" }),
({ "Ҽ","��","��","��","��","½","��","��","��" }),
});

#include "antirobot.h";
void question()
{
    	if (!ob) return;
    	message("channel", HIW+str+NOR, ob);
}

int do_answer(string arg)
{
    	object me = this_object();
    	object obj = this_player();

    	if (obj != ob) return 0;
    	if ( !arg ) return notify_fail("��ʽ answer <ID> \n");
    	if ( arg == ans ) {
		message_vision("$N���˵�ͷ��˵����OK��$n����æ�ɡ�\n", me, ob);
		message_vision("$NͻȻ��ʧ�����ˡ�\n", me);
    	} 
    	else {
		message_vision("$N̾�˿�������"+arg+"��"+ans+"�Ŷԣ���ô�򵥶��𲻳���ȥ��ͥ������Ѷ�ɣ�\n", me);
		move_to_court(ob);
    	}
    	destruct(this_object());
    	return 1;
}

void test_robot(object obj)
{
    	int len;
    	object *inv, test_ob, me = this_object();
	string id;
	mixed list;
	
    	ob = obj;
    	if (environment(ob)) {
    		inv = all_inventory(ob);
    		if( !sizeof(inv) ) {
    			destruct(me);
    			return;
    		}
    		inv = filter_array(inv, (:  !$1->is_character() :));
    		if( !sizeof(inv) ) {
    			destruct(me);
    			return;
    		}
    		test_ob = inv[random(sizeof(inv))];
    		list = test_ob->parse_command_id_list();
    		len = random(sizeof(list));
    		if( len > 8 ) len = random(8);
    		id = list[len];
		me->move(environment(ob), 1);
		message_vision("$N��Ȼ������$n��ǰ��\n", me, ob);
		set_leader(ob);
		list = numbers[random(sizeof(numbers))];
		tell_object(ob, "����ɱ���Դ�Ǹ���˵���������˻��飬���й��£������һ��С���ԡ���\n");
		str += test_ob->name(1)+HIW"���ĵ� "+list[len]+" �� id ��ʲô��(�� "+id[0..0]+" ��ͷ������ id ����鿴)\n";
		ans = id;
		timer = 180;
		call_out("test1", 60);
    	} 
    	else destruct(me);
}
