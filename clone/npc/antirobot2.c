// designed by Yu Jue

#include <ansi.h>

inherit NPC;

string key="";
string ans=" ";
string str = "����ɱ��˵�������� answer �ش���������Ӣ���г���������";

#include "antirobot.h";

void question()
{
    	if (!ob) return;
    	tell_object(ob, HIW+HIW+str);
    	tell_object(ob, key+NOR);
}

int do_answer(string arg)
{
    	object me = this_object();
    	object obj = this_player();

    	if (obj != ob) return 0;
    	if (!arg || strlen(arg) > 1) return notify_fail("����һ����ĸ������ϸ���롣\n");
    	if (arg==ans) {
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
    	int len, temp, t1, t2, t3;
    	object me = this_object();

    	ob = obj;
    	if (environment(ob) && !ob->is_fighting()) {
        	me->move(environment(ob), 1);
        	message_vision("$N��Ȼ������$n��ǰ��\n", me, ob);
        	set_leader(ob);
        	tell_object(ob, "����ɱ���Դ�Ǹ���˵���������˻��飬���й��£���ش�һ��С���⡣��\n");
        	temp = len = random(5)*2+7;
        	t1 = random(26);
        	while (temp--) {
            		do t2 = random(26); while (t2==t1);
            		key += "a";
            		key[<1] += t2;
        	}
        	t1 += 'a';
        	ans[0] = t1;
        	temp = random(len/2) + len/2 + 1;
        	str += chinese_number(temp)+"�ε���ĸ�ǣ�\n";
        	while (temp--) {
            		do t3 = random(len); while (key[t3]==t1);
            		key[t3] = t1;
        	}
        	key += "\n";
        	timer = 180;
        	call_out("test1", 60);
    	} 
    	else destruct(me);
}

