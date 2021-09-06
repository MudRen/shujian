// Npc: /d/tianshan/npc/zhubfan.c
// By Linux

#include <ansi.h>
inherit NPC;

void create()
{
	object ob;
	set_name("׿����", ({ "zhuo bufan", "zhuo", "bufan"}));
	set("long",  "����������������ƮƮ����Ŀ���㣬�����ǡ�����׿������\n");
	set("gender", "����");
	set("title","һ�ֻ۽���");
	set("per",25);
        set("age", 56);
        set("shen_type",0);
        set("unique", 1);
	set("attitude", "peaceful");
      
        set("str", 25);
        set("int", 35);
        set("con", 40);
        set("dex", 40);

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 4000);
        set("max_jing", 4000);
        set("neili", 4000);
        set("eff_jingli", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
	set("combat_exp", 4000000);

        set_skill("force",280);
        set_skill("dodge",280);
        set_skill("parry",280);
        set_skill("hand",280);
        set_skill("strike",280);
        set_skill("sword",280);

        set_skill("zhemei-shou",28);          //��ң��÷��(hand)
        set_skill("liuyang-zhang",280);        //��ɽ������(strike)(unarmed)
        set_skill("yueying-wubu",280);       //ƾ���ٷ�(dodge)
        set_skill("bahuang-gong",280);        //�˻�����Ψ�Ҷ���(force)
	set_skill("tianyu-qijian",280);     //��ɽ����(sword)
	set_skill("literate", 150);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "tianyu-qijian");
	map_skill("sword", "tianyu-qijian");

        prepare_skill("hand","zhemei-shou");
        prepare_skill("strike","liuyang-zhang");

	setup();

        add_money("silver",20+random(20));
        if (clonep()) {
		ob = unew(BINGQI_D("sword/zhougong-jian"));
		if (!ob) ob = unew(BINGQI_D("changjian"));
		ob->move(this_object());
		ob->wield();
		carry_object(ARMOR_D("cloth"))->wear();
	}       
	call_out("remove_ob", 200, this_object());
}

int remove_ob(object ob)
{
	if(!ob) return 1;
	tell_room(environment(ob), "\n"+HIR+ ob->query("name")+"˵�����������ܾ�ս���Ҹ���ˣ�\n" NOR,({  }));
	destruct(ob);
	return 1;
}
