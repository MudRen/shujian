// huangdaxian.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW "�ƴ�����" NOR, ({ "huang daxianren", "huang", "daxian", "daxianren" }) );
	set("nickname", HIR "ͨ��֪��" NOR);
	set("gender", "����" );
        set("age", 190);
	set("long", "��λ�ƴ������������һ������Ī������ӡ�\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
        set("no_get", 1);
	set("inquiry", ([
		"name" : "�����ջƣ���Ϊ�������׼�����Դ�Ҷ������Ϊ�ƴ����ˡ�",
		"rumors" : "Ҫ��֪��������Ļ������裬�Ǿ������������ɡ�",
		"����" : "�ҵļ�Ǯ��������಻�٣�ֻҪ�����ƽ�"
	]) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"�ƴ�����ߺ�ȵ����������㣬��Ǯ���������������ƽ�\n",
		"�ƴ����˶���˵��������������������������Σ�\n",
	}) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	int per,kar,pur;
	if (ob->query("money_id") && ob->value() >= 20000) 
	{
		message_vision("�ƴ����˶���$N������һ��\n", who);
		who->set_temp("suanming_paid", 1);
		per = who->query("per");                
		kar = who->query("kar");
		pur = who->query("pur");
    command("say �����ò��"+per+"��,��Դ��"+kar+"��,������"+pur+"��");
    return 1;     
	}
	return 0;
}

