// xian. ���ϰ�

inherit NPC;

string rumor();
string mao18();
void create()
{
	set_name("���ƹ�", ({ "xian zhanggui", "xian", "zhanggui" }));
	set("title", "�������ƹ��ϰ�");
        set("unique",1);
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 45);
	set("long", "ϴ�ƹ�Ӫ�洫�������������ƹ����ж��ꡣ\n");
	set("combat_exp", 2000);
	set("inquiry", ([
		"name" : "�͹�������ʲô����С�����ƹ�ͺá�",
                "rumors" : (: rumor() :),
                "éʮ��" : (: mao18() :),
		"here" : "����������ѽ���͹�����Ȼ��֪����",
		"����" : "�����������ѽ���͹����ⲻ������ë¿��ë¿��",
		"�һ���": "��˵�Ƕ����ϵ�С���������ݵĶ����ߣ������߿��ܲ��ܹʹ��ɣ�",
		"����": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"jpei": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"����" : "����ش��������ߣ�����õúܡ�",
	]) );
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	setup();
}

string rumor()
{
        object me = this_player();

        me->set_temp("mao18/jg_pass1",1);
        return "��˵�и���������ʲôʮ�˵�Խ���ˣ��ٸ�����׽�á�";
}

string mao18()
{
        object me = this_player();

        if (me->query_temp("total_pay") && me->query_temp("mao18/jg_pass1")) {
                me->delete_temp("mao18/jg_pass1");
                me->set_temp("mao18/jg_pass",1);
                return "�ԣ������Ǹ����ˡ���˵�Ǹ��������㵽����Ժ���ȥ�ˡ�";
        }
        return 0;
}

void init()
{	
}

int accept_object(object who, object ob)
{
	int pay, value;

	if (ob->query("money_id")) {
		if (!(pay = who->query_temp("total_pay"))) {
			tell_object(who, "���ƹ�æ������Ц�������͹����ֲ�ǷС���Ǯ���ͱ�����ͷ��Ѱ�����ˡ���\n");
			return 0;
		}
		if (!who->query_temp("to_pay")) {
			tell_object(who, "���ƹ�˵�������͹����Ƚ���(pay)�ٸ����\n");
			return 0;
		}
		value = ob->value();
		if (value >= pay) {
			who->delete_temp("to_pay");
			who->delete_temp("total_pay");
			if (value == pay) message_vision("���ƹ���������Ц����$N����������л�͹��������ߺá���\n", who);
			else message_vision("���ƹ���������Ц����$N����������л�͹�����С�ѣ��϶��������������ˣ����ߺá���\n", who);
			return 1;
		}
		else {
			pay -= value;	
			message_vision("���ƹ����$N˵����������������" + chinese_number(pay) + "�ġ���\n", who);
			who->set_temp("total_pay", pay);
			return 1;
		}
	}
	return 0;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��ɥ�ط������ƹ���ڸ߸ߵĹ�̨���棬��������\n", ob);
}

void unconcious()
{
	say( "���ƹ��һ�������Ҳ����ˣ��������ң���\n");
	say( "����ӹ�̨�������һ��Сͯ���������ƹ����������һ��ҩ������ˡ�\n");
	say( "Ƭ��֮�䣬���ƹ��ָֻ��˾��񣬡��ٺ١���Ц��������\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}
