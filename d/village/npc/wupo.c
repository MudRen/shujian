#include <ansi.h>
inherit NPC;

string ask_xianhai();

void create()
{
	set_name("����", ({ "wu po", "po", "wu" }) );
	set("gender", "Ů��" );
	set("shen_type", -1);
	set("age", 80);
	set("attitude", "peaceful");
	set("unique", 1);
	set("combat_exp", 25000);

	set("long",
                "���Ǹ��������ƣ�������ǿ�����ţ���˵�Ѿ����ϰ�����͡�\n"+
		"�������ֵ��ǿ��Ը����������ˡ�������ȥ������ĵ��ˣ�\n"+
		"��˵����ǮԽ�࣬Խ���顣\n" );

        set("chat_chance", 3);
        set("chat_msg", ({
                "���źٺ�һЦ: �����ҷ�����ǿ����ʲô�¾���˵�ɡ�\n",
        }));

        set("inquiry", ([
		"����"   : (: ask_xianhai :),
        ]) );

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

string ask_xianhai()
{
	object me;
	me = this_player();
	if ( (int)me->query("shen") > 0 ){
		command("look "+me->query("id"));
		me->set_temp("about_shen", 1);
		return "�ҿ���λ" + RANK_D->query_respect(me) + "һ��������ȴҲ�����⺦�˵ķ��ӡ�\n";
	}
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("����˵������ɱ�ң��㲻Ҫ���ˣ����㿴���ҵ�����!\n", ob);
	message_vision("ֻ���������૵����˼����������$N������һ������û�ж����ˣ�\n", ob);
	command("hehe");
	ob->add_busy(10);
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say("������Ц�����������˵�,�ٴ�Ҫ������\n");
	command("hehe");
}

void die()
{
	unconcious();
}

int accept_object(object me, object ob)
{
	int nmoney;
	nmoney=ob->value();
	if(!me->query_temp("about_shen"))
		return notify_fail("����˵������λ" + RANK_D->query_respect(me) + "�����ǳ��μ��棬Ϊ���ʹ˺���\n");
	if( ob->query("money_id") && nmoney >= 10000 ) {
		me->add("shen",-1 * random(nmoney/2));   // 1 gold random(5k) -shen 
		message_vision("һ���Ц���У�ֻ�����Ŵӱ����ó�һ��С���˽���$N���ǲ��˵�ģ������$N�ĳ�ҡ�\n$N��һֻ����ݺݵ����Ų��ˣ����не����������������㡣\n", me);
		message_vision("$N���ĵ�ӿ��һ��а�\n", me);
		me->delete_temp("about_shen");
		me->add_busy(random(2));
		return 1;
	}
	else {
		message_vision("����ŭ��������ô��Ǯ����򷢽л���ô����\n", me);
		return 0;
	}
}
