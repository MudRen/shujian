// guanbing.h
// all include �ٱ����佫 by Lklv 2002.1.18
// update by lsxk@hsbbs �����Զ�������grin

#include <get_place.h>
#include <ansi.h>

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player())
	 && living(this_object())
	 && ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
        }
}

int accept_fight(object me)
{
    string p;
    object env = environment(this_object());

    p = get_place(file_name(env));
	if (!me) return 0;
    if(me->query("guanbing_chat_alarm"))
    message("system",HIY"��"+HIR+"�ٸ���Ѷ"+HIY+"��"+this_object()->query("name")+"("+this_object()->query("id")+")����λע�⣡"+HIC+p+HIG+env->query("short")+HIY+"���⵽�������븽��ƽ��Ѹ�ٳ���Σ�յ�����\n"NOR,users());

	if (query("id")=="wu jiang"){
		command("pei ");
		command("say �ҶԳ�͢�������񣬽����ô�ү�ҽ�ѵ��ѵ�㣡\n");
		fight_ob(me);
		return 1;
	}
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	if (!is_killing(me->query("id")))
		me->add_condition("killer", 5);
	kill_ob(me);
	return 1;
}

void kill_ob(object ob)
{
    string p;
    object env = environment(this_object());

    p = get_place(file_name(env));
	if (!ob) return;

    if(ob->query("guanbing_chat_alarm"))
    message("system",HIY"��"+HIR+"�ٸ���Ѷ"+HIY+"��"+this_object()->query("name")+"("+this_object()->query("id")+")����λע�⣡"+HIC+p+HIG+env->query("short")+HIY+"���⵽�������븽��ƽ��Ѹ�ٳ���Σ�յ�����\n"NOR,users());

	if (query("id") == "wu jiang")
		command("say �㣡�㣡�㣡���˰������������������������");
	else
		command("say �����������ߣ�����");
	::kill_ob(ob);
}
