inherit NPC;
string ask_me();

void create()
{
        set_name("��������", ({
                "huiyun zunzhe",
                "huiyun",
		"zunzhe",
	}));
	set("long",
                "����һλ���΢�ֵ���ɮ����һϮ�಼������ġ�\n"
                "̫��Ѩ΢΢���ݣ�һ��û����ɵ����ӡ�\n"
	);

        set("gender", "����");
	set("attitude", "friendly");
       set("class", "bonze");
	set("age", 50);
	set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 850);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 150);
        set("combat_exp", 250000);
	set("score", 100);
        set_skill("force", 100);
        set_skill("yijin-jing", 100);
        set_skill("dodge", 100);
        set_skill("shaolin-shenfa", 100);
        set_skill("club", 100);
        set_skill("weituo-gun", 120);
        set_skill("parry", 100);
        set_skill("buddhism", 100);
        set_skill("literate", 100);

    map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("club", "weituo-gun");
        map_skill("parry", "weituo-gun");
        create_family("������", 38, "����");
	setup();
        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
	set("inquiry", ([
		"��������"       : (: ask_me :),
                "�����ô���"     : (: ask_me :)
	]));
}
 int accept_object(object who, object ob,object me)
{
        mapping fam;
        me=this_object();
        if (ob->query("id")!="baitie")
         {
           command("say ��������������ʲô?\n");
// ����baitie��������������Ʒ River@SJ
             return 0;
          } 
        if(!who->query_temp("baitie")){
                command("say ��İ����������ģ�����ת������ˡ���Ӵ���");
                return 1;
	  }
        if (!(fam = this_player()->query("family")) 
           || fam["family_name"] != "������"){
                command("angry "+who->query("id"));
                command("say �ð����㹫Ȼ��ս���ɣ���������֪��������");
                kill_ob(this_player());
        return 1;
             }
         call_out("destroying", 1, me, ob);           
         command("hmm");
         command("say ����������ʥ������������֣����и�����һ�������
                      ���������϶����ܴ��ۡ�");
         command("say �˺����ǿ��������������Ա���Ϊ�ʹ�˵���λ���ǻ�
                      �ĳ����ղ��ܳ��ҷ�Ҹ�ɮ���͡�");
         command("say ��������������Ҳʵ������������֮������Ҳ�в��ٸ�ɮ��
                      �ͣ������������ޡ����ҷ�����������书����ĩ��"+
                      RANK_D->query_respect(this_player()) +"�αض�Ҫð�˴��գ�
                      �����Ծ���");
        this_player()->set_temp("try",1);
                     return 1;

}
 
#include "huu.h"
