// youxun.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��Ѹ", ({ "you xun", "xun","you"}));
	set("nickname", "��������");        
        set("long", "����ͷ����ͺ��һ�����룬�ʷ����֣�������⣬����ʮ�ֺͰ����ס�\n");
        set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 25);
	set("con", 21);
	set("dex", 34);
        
	set("max_qi", 1200);
	set("qi", 1200);
        set("max_jing", 1200);
	set("jing", 1200);
        set("neili", 1700);
        set("max_neili", 1700);
	set("eff_jingli", 1000);
	set("jingli", 1000);
        set("jiali", 50);
        set("combat_exp", 300000);
        set("shen", -2500);

	set_temp("apply/attack", 40);
	set_temp("apply/defence", 40);

        set_skill("parry",130);
        set_skill("force",130);        
        set_skill("dodge",130);
        set_skill("strike", 130);
        set_skill("tianmo-zhang", 140);
        set_skill("literate", 100);
        set_skill("ding-dodge",130);
	set_skill("tianmo-gong", 130);	
	set_skill("tianmo-jian", 130);
	set_skill("sword", 130);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
	map_skill("sword", "tianmo-jian");
	map_skill("parry", "tianmo-jian");
	map_skill("strike", "tianmo-zhang");
	prepare_skill("strike", "tianmo-zhang");
        setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();        
}
