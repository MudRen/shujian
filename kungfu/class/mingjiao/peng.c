// peng.c ��Ө��
// Modify By River@sj 99.06
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("��Ө��", ({ "peng yingyu","peng","yingyu" }) );
        set("title", "������ɢ��");
        set("gender", "����");
        create_family("����",36,"ɢ��");
        set("age",51);
        set("class", "bonze");
        set("long","������������ɢ��֮һ���˳�����С�\n");
        set("rank_info/respect","��ʦ");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("per", 12);
        set("combat_exp", 600000);
        set("unique", 1);

        set_skill("sword",80);
        set_skill("cuff",80);
        set_skill("literate",130);
        set_skill("force",80);
	set_skill("parry", 80);
        set_skill("dodge",80);
        set_skill("liehuo-jian",85);
        set_skill("piaoyi-shenfa",85);
        set_skill("shenghuo-shengong",80);
        set_skill("hand",80);
        set_skill("qianye-shou",85);
        map_skill("force","shenghuo-shengong");
        map_skill("hand","qianye-shou");
        map_skill("dodge","piaoyi-shenfa");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        prepare_skill("hand", "qianye-shou");

        set("max_qi",1500);
        set("max_jing",1200);
        set("jiali",50);
        set("eff_jingli",1100);

        setup();
        carry_object("/d/mingjiao/obj/yel-cloth")->wear();
}

void attempt_apprentice(object ob)
{     
        command("say �����ӷ����գ����գ�ƶɮ����ò��յ����ˡ�");
        command("say ��λ"+RANK_D->query_respect(ob)+"������ذɡ�");
        return;
}
