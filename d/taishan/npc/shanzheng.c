// shanzheng.c ����

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "shan zheng", "shan", "zheng" }) );
	set("gender", "����");
        set("nickname","�����й�");
        set("title","����ׯׯ��");
        set("age", 55);
	set("long","��������⣬������ͯ�պ׷������֡�\n"+
                   "����ȴ��ǫ�ͣ����ƽ����ϴ�˵�ĳ������顣\n");
        set("combat_exp", 400000);
        set("shen_type", 1);
	set("attitude", "firendly");
        set("unique", 1);

        set("str", 28);
        set("con", 26);
	set("int", 20);
	set("dex", 24);
        set("per", 20);

        set("max_qi", 1000);
        set("max_jing", 900);
        set("neili", 1000);
        set("eff_jingli", 900);
        set("max_neili", 1000);
        set("jiali", 10);

        set_skill("force", 100);  
        set_skill("yijin-jing", 100);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("strike", 100);
        set_skill("parry", 100);
        set_skill("qingmang-jianfa", 100);
        set_skill("zhongjia-zhang",100);
        map_skill("sword", "qingmang-jianfa");
        map_skill("parry", "qingmang-jianfa");
        map_skill("force","yijin-jing");
        map_skill("strike","zhongjia-zhang");
        prepare_skill("strike","zhongjia-zhang");

	setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/jinduan")->wear();
}
