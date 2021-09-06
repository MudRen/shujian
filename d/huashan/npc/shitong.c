// NPC: /d/huashan/npc/shitong.c
// Date: Look 99/03/25

inherit NPC;

string ask_gonglao(object me);

void create()
{
	set_name("��ͯ", ({ "shi tong" }));
	set("long", "����һ��ר���ڼ�̳�̷��Сͯ��\n");
	set("age", 17);
	set("combat_exp", 20000);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("str", 20);
       set("attitude", "peaceful");
	set("shen_type", 1);

	set("max_qi", 300);
	set("qi", 300);
	set("max_jing", 300);
	set("jing", 300);
	set("eff_jingli", 300);
	set("jingli", 300);
	set("max_neili", 300);
	set("neili", 300);

	set_skill("huashan-jianfa", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("huashan-shenfa", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zixia-gong", 50);
	set_skill("strike", 50);
	set_skill("hunyuan-zhang", 50);

	map_skill("strike", "hunyuan-zhang");
	map_skill("force", "zixia-gong");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");

	prepare_skill("strike", "hunyuan-zhang");
	
        set("inquiry", ([
              "����" : (: ask_gonglao :),                        
        ]));

	setup();
	carry_object(BINGQI_D("sword/sword"))->wield();
	carry_object(ARMOR_D("armor/cloth"))->wear();
}

string ask_gonglao(object who)
{
	mapping fam;
	int i;
        object me=this_player();
        fam = me->query("family");
	i = me->query("job_time/��ɽ");
        if(!intp(i = me->query("job_time/��ɽ"))) return "��ûΪ�һ�ɽ���ճ����κ�����������ʲô������?"; 
       	if(random(10) > 3) return RANK_D->query_respect(me)+"Ϊ��ɽ������Щ���£��Ͳ�Ҫ������ȥ���ˡ�\n";
        message_vision("$Nָ�ż�̳��$n˵����"+RANK_D->query_respect(me)+"�Ѿ�Ϊ��ɽ��������" + CHINESE_D->chinese_number(i) + "�����¡�\n",who,me);
        return RANK_D->query_respect(me)+"���͸ɰ���";
}
