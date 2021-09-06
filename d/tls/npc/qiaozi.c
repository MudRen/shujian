// ���� by leontt

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string axe();
string strike();
void create()
{
        set_name("����", ({ "qiao zi", "qiao", "zi" }) );
        set("gender", "����" );
        set("age", 40);
        set("str", 30);
        set("con", 30);
        set("dex", 25);
        set("int", 25);
        set("per", 20);
        set("attitude", "friendly");

        set("max_qi", 5000);
        set("max_jing", 2800);
        set("eff_jingli", 3600);
        set("neili", 8000);
        set("qi", 5000);
        set("jingli", 3600);
        set("max_neili", 8000);
        set("jiali", 150);
        
        create_family("����", 13, "����");
        set("chat_msg_combat", ({
                (: random_move :)
        }) );
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("long", 
        "������������һ���ɲ���������һ�����ӣ�����ȥ��һ���Է�\n"+
        "ֻ������ɫ��׳����̬������������������Ǵ󽫾��а������磬\n"+
        "�������ֲ����Ѷ�����ɽ���Բ񣬱ص����Ǹ�߳����Ƶ�ͳ�� \n"+
        "Ԫ˧��\n");
        
        set("combat_exp", 2300000);
        set("score", 50000);
        set("startroom","/d/tiezhang/road-2"); 

        set("chat_chance_combat", 10);
        set("chat_msg_combat",({
         (: perform_action, "axe.jingtian" :),
         (: exert_function, "qi" :) 
        }));
           
        set_skill("parry", 280);
        set_skill("dodge", 280);
        set_skill("force", 280);
        set_skill("axe", 280);
        set_skill("literate", 200);
        set_skill("strike", 280);
        set_skill("qingyan-zhang", 280);
        set_skill("qiantian-yiyang", 280);
        set_skill("pangen-fu", 280);
        set_skill("tianlong-xiang", 280);
        set_skill("finger", 280);
        set_skill("yiyang-zhi", 280);
        set_skill("buddhism", 140);
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "yiyang-zhi");
        map_skill("axe", "pangen-fu");
        map_skill("force", "qiantian-yiyang");
        map_skill("strike", "qingyan-zhang");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger","yiyang-zhi");
        
        set("inquiry", ([
            "name": "�������ʲô? �������ʲô�����ŷ������ʲô��ϵ��",
            "here": "�������Ҳ����˵�ģ�",
            "��������" : (: axe :),
            
        ]));

        set("chat_chance", 10);
        set("chat_msg", ({
"�ǳؾ㻵��Ӣ�۰��ڣ����������ཻ��������˥����Ϊ������\n",
"�ƼҲ�����Ұܣ���̬�����Ʊ�ġ�����Ҳ����ز�٣�Ҳ����ز��\n",
"������ϣ�ƾ��ң����������������ɥ�����Բԣ�ˮãã����̨�������˽���ǧ��תͷ������������Ҳ���ó�������Ҳ���ó�����\n",

        }) );
        
        carry_object("/clone/armor/b_cloth")->wear();
        carry_object("/clone/weapon/axe")->wield();
        
        setup();
}

string axe()
{
        mapping fam = this_player()->query("family");
        object ob;        
        if(!fam || fam["family_name"] != "������")
           return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
        if(this_player()->query_skill("axe",1) > 100)
           return "��ĸ����Ѿ���һ�������ˣ��Ȿ�����ûʲô�ã������������˰�";        
        ob = unew("/clone/book/axe-book");
        if(!clonep(ob))
           return "�������ˣ��ҵġ������������Ѿ������������ˡ�";   
        if(clonep(ob) && ob->violate_unique()){
           destruct(ob);
           return "�������ˣ��ҵġ������������Ѿ������������ˡ�";  
           }      
        ob->move(this_player());
           return "�ðɣ��Ȿ���������������͸����ˡ�";
}

void attempt_apprentice(object ob)
{     
        if( (string)ob->query("gender") == "Ů��" ){ 
                command ("say �Ҵ����书��Ҫ����֮�壬С�����ҿɲ��հ�!");
                return;
        }
        if (ob->query("tls")){ 
                command ("say ���Ѿ��������³��ҵ����ˣ��Ҳ����������ˣ�\n");
                return;
        } 
        if( (int)ob->query_skill("qiantian-yiyang",1) < 150  ){      
                command ("hmm");
                command ("say ��Ǭ��һ�������֮��ҿɲ�����?");
                return;
        }
        if(ob->query_str() < 30){
                command("say Ҫѧ�ҵĿ��ұ��죬���������ߣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ�������");
                return;
        }
        if ((int)ob->query("job_time/����") < 300){
                command ("say �ҿ���Ϊ���������������Ļ���������Ŭ�����ɣ�");
                return;
        }      
        
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("giggle1");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
        ob->set("title","�����ʮ�Ĵ�����");
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

