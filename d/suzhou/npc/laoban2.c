inherit NPC;
inherit F_BANKER;

void create()
{
	set_name("���ϰ�", ({"sun laoban", "sun", "laoban"}));
	set("title", "Ǯׯ�ϰ�");
	set("nickname", "һë����");
	set("gender", "����");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 500); 
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);
set_skill("unarmed", 150);
set_skill("dodge", 150);
set("combat_exp",300000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
	"���ϰ彾����˵�����������Ѿ����ϰ������ʷ���ڽ��Ͽ���˵�ǵ�һ�ҡ�\n",
	"���ϰ忪Ц��˵�����ڱ����Ǯ����Ϣ��ȡǮ�հٷ�֮�������ѣ��͹������Ű�ɡ�\n"
	}));

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	add_money("silver", 50);
}
void init()
{
	::init();
	add_action("do_check", ({"check", "chazhang", "����"}));
	add_action("do_convert", ({"convert", "duihuan", "�һ�"}));
	add_action("do_deposit", ({"deposit", "cun", "��"}));
	add_action("do_withdraw", ({"withdraw", "qu", "ȡ"}));
}
