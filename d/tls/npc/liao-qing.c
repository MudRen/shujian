inherit F_MASTER;
inherit NPC;
void create()
{
        set_name("������ʦ", ({ "liaoqing chanshi","liaoqing","chanshi"}) );
        set("nickname", "��Ϊ����");
        set("long", "������ʦ�Ǳ��δ�ʦ�ĵ��ӣ�����Լ��ʮ���꣬
������Ϊ��Ц�ݴ��ӡ�\n");
        set("gender", "����" );
        set("class", "bonze");
        set("attitude", "friendly");
        set("age", 34);
        set("shen_type", 1);
        set("str", 25);
        set("int", 28);
        set("con", 23);
        set("dex", 22);
        create_family("������", 14, "����");

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 5000);

        set_skill("force", 100);
        set_skill("qiantian-yiyang", 110);
        set_skill("dodge", 80);
        set_skill("tianlong-xiang", 95);
        set_skill("parry", 80);
        set_skill("duanjia-jianfa", 110);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("buddhism", 100);
        set_skill("literate", 80);
        set_skill("qingyan-zhang", 110);
        map_skill("force", "qiantian-yiyang");
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "qingyan-zhang");
        map_skill("sword", "duanjia-jianfa");
        map_skill("strike", "qingyan-zhang");
        prepare_skill("strike","qingyan-zhang");                
        
        setup();
        carry_object(BINGQI_D("changjian"))->wield(); 
        carry_object("/d/tls/obj/jiasha1")->wear(); 
        carry_object("/d/tls/obj/sengxie")->wear();
}
#include "liao.h";
