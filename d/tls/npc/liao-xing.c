inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("������ʦ", ({ "liaoxing chanshi","liaoxing","chanshi"}) );
        set("long", "������ʦ�Ǳ����ʦ�ĵ��ӣ�����ͬ�������������̸��
��������ѧ��ȴ��ʮ�ֿ̿��ù���\n");
        set("nickname", "������");
	set("gender", "����" );
        set("attitude", "friendly");
	set("class", "bonze");
	set("age", 34);
	set("shen_type", 1);
	set("str", 24);
	set("int", 24);
	set("con", 22);
	set("dex", 22);
        create_family("������", 14, "����");

	set("qi", 1100);
	set("max_qi", 1100);
	set("jing", 1200);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 600000);
	set("score", 6000);

	set_skill("force", 80);
	set_skill("qiantian-yiyang", 80);
	set_skill("dodge", 80);
	set_skill("tianlong-xiang", 80);
	set_skill("parry", 80);
        set_skill("sword", 80);
	set_skill("finger", 80);
	set_skill("yiyang-zhi", 80);
	set_skill("buddhism", 90);
	set_skill("literate", 80);
//        set_skill("whip", 80);
//        set_skill("cihang-bian", 80);
        map_skill("whip", "qingxu-bian");
	map_skill("force", "qiantian-yiyang");
	map_skill("dodge", "tianlong-xiang");        
	map_skill("parry", "yiyang-zhi");
        map_skill("sword", "yiyang-zhi");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");		

        setup();       
 //       carry_object(weapon)->wield();
        carry_object("/d/tls/obj/jiasha1")->wear();
        carry_object("/d/tls/obj/sengxie")->wear();
}
#include "liao.h";
