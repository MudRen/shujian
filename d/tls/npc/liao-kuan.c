inherit F_MASTER;
inherit NPC;
void create()
{
        set_name("�˿���ʦ", ({ "liaokuan chanshi","liaokuan","chanshi"}) );
        set("nickname", "��Ϊ����");
        set("long", "�˿���ʦ�Ǳ����ɵĵ���λ���ӣ�����Լ��ʮ��
�����������������Ӻ���\n");
        set("gender", "����" );
        set("class", "bonze");
        set("attitude", "friendly");
        set("age", 41);
        set("shen_type", 1);
        set("str", 25);
        set("int", 22);
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

        set_skill("force", 90);
        set_skill("qiantian-yiyang", 100);
        set_skill("dodge", 80);
        set_skill("tianlong-xiang", 80);
        set_skill("parry", 80);
        set_skill("duanjia-jianfa", 100);
        set_skill("strike", 80);
        set_skill("sword", 80);
        set_skill("buddhism", 100);
        set_skill("literate", 80);
        set_skill("qingyan-zhang", 100);
        map_skill("force", "qiantian-yiyang");
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "qingyan-zhang");
        map_skill("sword", "duanjia-jianfa");
        map_skill("strike", "qingyan-zhang");
        prepare_skill("strike","qingyan-zhang");                
        set("inquiry",([
                "������"  : "�����Ŷ���ʧ�ޣ�Ѱ���˵Ȳ�С�ľͻ�ˤ����ȥ",
                "��ɽ"  : "���˰����ž��Ǻ�ɽ�ˣ�����������ɮǱ��֮�أ�Ѱ���˵Ȳ��ý���",
        ]));
        setup();
        carry_object(BINGQI_D("changjian"))->wield(); 
        carry_object("/d/tls/obj/jiasha1")->wear(); 
        carry_object("/d/tls/obj/sengxie")->wear();
}
#include "liao.h";
