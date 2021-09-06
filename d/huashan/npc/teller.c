// NPC: /d/huashan/npc/teller.c
// Date: Look 99/03/25

inherit NPC;

void tell_fortune();

int do_forge();

void create()
{
	set_name("������", ({ "li tiezui", "li" }) );
	set("gender", "����" );
	set("age", 48);
	set("long", "�������Ǹ������ԵĽ�����ʿ�������д���š�������\n");

	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 15);
	set("shen_type", -1);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set("combat_exp", 30000);

	set("attitude", "peaceful");
	set("inquiry", ([
		"����" : "������˵�����ҽ���û���飬���㣬���㡣\n",
		"д��" : "������˵��������д�ţ�ÿҳ��ʮ�ġ�\n",
		"д����" : "������˵���������ø����ּ�д������ÿ������������\n",
//		"α��" : (: do_forge :),
	]) );
	setup();
	carry_object(ARMOR_D("cloth"))->wear();

	add_money("silver", 5);
}

int do_forge()
{
	say("��������ֻ�۾�����ɨ��ɨ�����ٺٺ١��ĸ�Ц�˼���...\n");
	write("��������������˵���������Ҵ�ţ����֤��ĸ�ԭ������һģһ����ÿ����\n"+
		"	            ��ʮ�������������ۡ�\n");
	this_player()->set_temp("marks/��", 1);
	return 1;
}

int accept_object(object who, object ob)
{
	object letter;

	if ((string)ob->query("name")=="��ֽ") {
		if( who->query_temp("marks/��") ) {
			who->set_temp("marks/��3", 1);
			write("���������˵������������ף�������ʮ����������\n");
			who->set_temp("marks/��", 0);
			call_out("destroy", 1, ob);
			return 1;
		}
		else if( who->query_temp("marks/��2") ) {
			write("������ƤЦ�ⲻЦ�Ķ���˵����α������ſ��ǹ�ϵ�ش󰡣��ö�����ʮ����\n");
			who->set_temp("marks/��4", 1);
			who->set_temp("marks/��2", 0);
			call_out("destroy", 1, ob);
			return 1;
		}
//		say("������˵������д���˵��ţ����Ҹ�ʲô?\n");
		return 0;
	}
       
	if( ob->value() >= 5000 ) {
		if( who->query_temp("marks/��4") ) {
			write("���������˵���������������ˣ���" + RANK_D->query_respect(who)+ 
				"Ҫ�ǳ����£�ǧ������˵����ѽ��\n");
			say("���������" + who->query("name") + "һ�����š�\n");
			who->set_temp("marks/��4", 0);
			letter = new(__DIR__"obj/letter");
			letter->move(who);
			return 1;
		}
		if( who->query_temp("marks/��3") ) {
			write("������ƤЦ�ⲻЦ�Ķ���˵����α������ſ��ǹ�ϵ�ش󰡣��ö�����ʮ����\n");
			who->set_temp("marks/��4", 1);
			who->set_temp("marks/��3", 0);
			return 1;
		} 
		if( who->query_temp("marks/��") ) {
			write("���������˵��������α��ʲô��? �ܵ��ø��������ɡ�\n");
			who->set_temp("marks/��2", 1);
			who->set_temp("marks/��", 0);
			return 1;
		}
		say("������һ�漱æ��Ǯ��������һ��Ц����˵����" + RANK_D->query_respect(who) +
			"������ô�ҵ���\n");
		return 1;
	}
        if( ob->value() >= 500 ) {
		say("������Ц����˵��������д���ˣ������������ɣ���л���ա�\n");
		return 1;
	}
	if( ob->value() >= 50 ) {
		say("������Ц����˵������д���ˣ����պ��ˣ���л���ա�\n");
		return 1;
	}
	return 0;
}

void destroy (object ob)
{
	destruct(ob);
}
