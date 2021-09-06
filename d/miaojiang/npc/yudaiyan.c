#include <ansi.h>

inherit NPC;

string ask_me_1();
string ask_me_2();
string ask_me_3();

void create()
{
        set_name("�����", ({ "yu daiyan", "yu" }));
        set("nickname", "�䵱����");
        set("long", 
"������������������ӡ��䵱��������ҡ��򱻼�������������
�°뱲��ֻ���������϶ɹ��ˣ�����һ��ϴ�÷��׵���ɫ������
�κ��㲣���ɫ�Ұף�������������ǻ�����ʲô��\n");
        set("gender", "����");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 5);
        set("max_qi", 900);
        set("max_jing", 900);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 60);
        set("combat_exp", 750000);
        set("score", 60000);

        set_skill("force", 120);
        set_skill("yinyun-ziqi", 120);
        set_skill("dodge", 60);
        set_skill("tiyunzong", 60);
        set_skill("cuff", 90);
        set_skill("taiji-quan", 90);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("taiji-jian", 60);
        set_skill("literate", 100);

        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 2, "����");

        set("inquiry", ([
                "����۾���" : (: ask_me_1 :),
                "��ת������" : (: ask_me_2 :),
                 "��ҩ" : (: ask_me_3 :),
        ]));

        set("dan_count", 1 + random(2));
        set("wan_count", 1 + random(2));
        set("letter_count", 1 + random(1));

        setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}

string ask_me_1()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";

        if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
                return RANK_D->query_respect(this_player()) + 
                "���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ������򲻴�´������ɡ�";

        if (  present("jujing dan", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "���������ϲ����п�ҩ������������Ҫ�ˣ��޵�֮�������������̰��?!";

        if (query("dan_count") < 1) return "�Բ�������۾����Ѿ������ˡ�";

          ob = new("/d/wudang/npc/obj/jujing-dan");

        ob->move(this_player());
        add("dan_count", -1);

        message_vision("$N���һ������۾�����\n",this_player());
        return "�ðɣ���ס�������䵱ʥҩ���������׸��ˡ�";

}


string ask_me_2()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";

        if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
                return RANK_D->query_respect(this_player()) + 
                "���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ������򲻴�´������ɡ�";

        if (  present("jieqi wan", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "���������ϲ����п�ҩ������������Ҫ�ˣ��޵�֮�������������̰��?!";

        if (query("wan_count") < 1) return "�Բ�������۾����Ѿ������ˡ�";

        ob = new("/d/wudang/npc/obj/jieqi-wan");
        ob->move(this_player());


        message_vision("$N���һ�ž�ת�����衣\n",this_player());
        return "�ðɣ���ס�������䵱ʥҩ���������׸��ˡ�";

}
string ask_me_3()
{
        mapping fam;
        object applicant;
        object ob;
        int exp;

        applicant=this_player();
        if (!(fam = applicant->query("family")) || fam["family_name"] != "�䵱��")
        return RANK_D->query_respect(this_player())+"�뱾��������������̸Ϊ���ɲ�ҩ����";
        exp=(int)applicant->query("combat_exp",1); 
        if(exp>60000)
         return "�㻹�Ƕ���ѧ���գ���ҩ���������ʦ����ȥ���ɡ�\n"; 
        if(exp<10000)
         return "�㻹̫С����ҩ��һ��Σ�գ������ڲ��ʺ�ȥ��\n";

        if((int)applicant->query_skill("medicine", 1) < 20){
         command("shake "+(string)applicant->query("id"));
         return "�㲻ѧ��ݱ�ҩ�������ֱܷ����ҩ��!\n";
         } 
       if(interactive(applicant) && applicant->query_temp("mark/wd_mission"))  
         return "��Ϊʲ�ỹ��ȥ��ҩ��\n";
       if(interactive(applicant) && applicant->query_condition("wd_busy"))  
         return "�����Ѿ����㹻������ȥ��ҩ����\n";
   
        ob = new("/u/dubei/wudang/obj/yaolou");
        ob->move(applicant);
        applicant->set_temp("mark/wd_mission",1);
        applicant->apply_condition("wd_busy",10);
        return "�䵱������ҩ���Ʊ�������Ҫ����ƣ��ۻƺ��ٻ���ζ��ҩ�Ƴɣ�����
�䵱��ɽ���д˲�ҩ��"+RANK_D->query_respect(applicant)+"����������࣬���Ե��������ҿ���";
}

int accept_object(object who, object ob,object me)
{
        if (ob->query("id") != "yao lou" ){
             command("? "+(string)who->query("id"));
             return 0;
             }
       if(!present("ma huang", ob)){
             command("say �����û�вɵ���ư�����");
             return 0;
             }
       if(!present("teng huang", ob)){
             command("say �����û�вɵ��ٻư�����");
             return 0;
             }
       if(!present("xiong huang", ob)){
             command("say �����û�вɵ��ۻư�����");
             return 0;
             }
       if(!who->query_temp("mark/wd_mission")){
             command("say �㲢û����ȥ��ҩ������");
             return 0;
             }
        command("pat " + who->query("id"));
        command("say ��������ͣ����ձ������ɡ�\n");
        call_out("destroying", 1, ob);        
        who->add("combat_exp",(3+random(10))*10);
        who->add("potential",(3+random(10))*3);
        who->set("wd_job",1);
        who->delete_temp("mark/wd_mission");
        return 1;
}
void destroying(object obj)
{
        destruct(obj);
        return;
}
