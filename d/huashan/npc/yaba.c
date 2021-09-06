// NPC: /d/huashan/npc/yaba.c
// Date: Look 99/03/25

inherit NPC;

void create()
{
	set_name("�ư�", ({"yaba"}));
	set("long","�ưͼ����㣬˫�ֱȻ����������������������������������\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 31);
	set("int", 31);
	set("con", 31);
	set("dex", 31);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 0);
	set("combat_exp", 400000);
	set("score", 5000);
	set("chat_chance_combat",40);
       set("chat_msg_combat", ({
       (: perform_action, "cuff.leidong" :),
	(: perform_action, "strike.wuji" :),
	}));
       set_skill("sword",  150);
       set_skill("dodge",  150);
       set_skill("unarmed",150); 
       set_skill("force",  150);
       set_skill("parry",  150);
       set_skill("literate",150);
	set_skill("cuff", 150);
	set_skill("poyu-quan", 150);
	set_skill("hunyuan-zhang", 150);
	set_skill("strike", 150);
       set_skill("huashan-jianfa",150);
       set_skill("huashan-shenfa",150);
       set_skill("zixia-gong",150);

	map_skill("force", "zixia-gong");
	map_skill("strike", "hunyuan-zhang");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
       map_skill("dodge", "huashan-shenfa");
	map_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");
	create_family("��ɽ��", 14, "����");

	setup();
	carry_object(BINGQI_D("sword/sword"))->wield();
	carry_object(ARMOR_D("armor/cloth"))->wear();
 	
}

void init()
{
	object me = this_player();
	add_action("do_follow","follow");
	add_action("do_kill","kill");
	::init();
	if (me->query("family/family_name") == "��ɽ��" && me->query_temp("fill") > 0) {
	write("�ư������ƱȻ��˰��죬���������������˼���Ͻ�����һ���߰�(follow yaba)��\n", me);
	}
	call_out("do_back", 7, me);
}

void do_back(object me)
{
	write("�ưͼ���û������������˼��ʮ�־�ɥ�����ˡ�����\n", me);
	destruct(this_object());
}
