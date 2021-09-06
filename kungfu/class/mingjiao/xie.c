// NPC xie.c лѷ
// Modify By River@sj 99.06
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_dao();
string ask_boat();
void create()
{
        object ob;
        set_name("лѷ",({"xie xun","xie","xun"}));
        set("title","���̻��̷���");
        set("nickname",HIY"��ëʨ��"NOR);
        set("long", "���������̵��Ĵ󻤷�֮һ�Ľ�ëʨ����\n"+
                    "����Ŀ�ΰ�쳣����ͷ��ɢ����ͷ����˫Ŀ��Ϲ��\n"+
                    "������ǰһվ���������ݣ���������һ�㡣\n");
        set("age", 56);
        set("attitude", "peaceful");
        set("shen", -13000);
        set("str", 30);
        set("per", 16);
        set("int", 29);
        set("con", 35);
        set("dex", 27);        
        set("max_qi", 2500);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("jiali", 70);
        set("combat_exp", 1350000);
        set("unique", 1);

        set_skill("cuff",160); 
        set_skill("dodge",160);
        set_skill("force", 160);
        set_skill("blade",160);
        set_skill("literate",110);
        set_skill("piaoyi-shenfa", 160);
        set_skill("qishang-quan",180);
        set_skill("hunyuan-yiqi", 160);
        set_skill("parry", 160);
        set_skill("lieyan-dao",160);        
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("cuff", "qishang-quan");
        map_skill("parry", "qishang-quan");
        map_skill("blade", "lieyan-dao");
        prepare_skill("cuff","qishang-quan");
        
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "strike.qishang" :),
                (: exert_function, "roar" :),
	}));

        set("inquiry", ([
                 "���޼�"  : "�����ҵ����ӣ����Ѻܾ�û�м������ˡ�",
                 "����ȭ��" : (: ask_me :),
                 "������"  : (: ask_dao :),
                 "��"  : (: ask_boat :),
                 "����"  : (: ask_boat :),
                 "�촬"  : (: ask_boat :),
                 "��ԭ"  : (: ask_boat :),
                 "����"  : "���������ǹ���ʦ������ɱ����һ���Ŀڣ��˳𲻹����죡",
        ]));

        create_family("����", 36, "����");
        setup();
        if (clonep()) {
                ob = unew(BINGQI_D("tulong-dao"));             
                if (ob){
                    ob->move(this_object());
                    ob->wield();
                    }
                carry_object(ARMOR_D("xiongpi"))->wear();
        }  
}

void attempt_apprentice(object ob)
{     
        command("say �Ϸ��յ��ӡ�");
        command("say ��λ"+RANK_D->query_respect(ob)+"������ذɡ�");
        return;
}

void kill_ob(object me)
{        
        command("stare "+me->query("id"));
        ::kill_ob(me);
}

string ask_me()
{
        mapping fam; 
        object me = this_player();
        if (!(fam = me->query("family")) || fam["family_name"] != "����")
                return "����ȭ����û��˵����";
        if (fam["master_name"] != "���޼�")
                return RANK_D->query_respect(me)+"������ذɣ���˵��������ɵľ���������ô��֪����";
        if (me->query("xie_qishang"))
                return "�Ҳ����Ѿ���������ȭ��������ô��Ҫ�ʣ�";
        if (!me->query_temp("marks/����"))
                return "��������ȭ�����������ӣ��������ˣ�";
        command("consider");
        command("say �޼��⺢�ӣ���ô�ɽ�����ȭ���������أ�");
        command("say Ҳ�գ��޼ɼ�Ȼ������������Ҿʹ�����ɡ�");
        me->set("xie_qishang", 1);
        me->delete_temp("marks/����");
        me->add("max_jingli", 50);
        me->add("max_neili", 50);
        command("whisper "+me->query("id")+" ����֮���������������˷δݸγ������뾫ʧ���㱣�������������Ƿ��");
        return "���ȥ�ɡ�";
}

string ask_boat()
{ 
        object me = this_player();
        if (!me->query("xie_qishang")) return "�����⼫�������뿪��ԭ��������Ĵ�����";
        command("say �����Ұ�������������ں�ɽ�����п���(chop)��ľ��Ȼ��Űᵽ�����촬(make)��");
            return "Ҳ��֪���������Ǻ������޼ɺ�������ô���ˡ�";
}

string ask_dao()
{
        mapping fam; 
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
        if(present("tulong dao",this_object())){
           command("wield dao");
           command("say �������𣬱����������������£�Ī�Ҳ��ӣ����첻����˭�����档");
           write("\nлѷ����������������ͷڤ˼����֮�ء�\n\n");
           this_player()->set_temp("xie_tld", 1);
           return "��Ѱ��������֮�أ���֮�����εñ�����......";
        }
        else return "�������𣬱����������������£�Ī�Ҳ��ӣ�";
}

int accept_object(object who, object ob,object me)
{
       me=this_object();
       if(ob->query("name") != "�������׼�" || ob->query("id") != "shouji") {
               command("say �Ϸ����������ûʲô��Ȥ����");
               return 0;
       }            
       if(ob->query("victim_user")) {
               command("say �ⲻ�ǳ������ⲻ�ǳ�����");
               return 0;
       }      
       command("say ��������������ͷ�� ��������ͷ��");
       command("chat ��������������������ͷ�� ��������ͷ��");
       call_out("destroy", 1, ob);
       if(ob->query("kill_by") != who){
               command("say ������������ɱ�İɣ�������ô�õ������ͷ�ģ�");
               return 1;
       }     
       if(who->query_temp("xie_tld") && present("tulong dao",me)){
           command("say �����Ҵ��ñ�����ѵ������ҵ�л��ֻ��ϧ�����������Ƕ�����");           
           command("give tulong dao to "+who->query("id"));
           who->delete_temp("xie_tld");
           return 1;
       }
       else{
           command("say �����Ҵ��ñ�����ֻ���������ҵ�л��ɣ�ֻ��ϧ�����������Ƕ�����");
           message_vision("$N����$nһ�鿾������ơ�\n", me, who);
           new(FOOD_D("xzhang"))->move(who);
           return 1;
      }
}

void destroy(object ob)
{
        destruct(ob);
        return;
}
