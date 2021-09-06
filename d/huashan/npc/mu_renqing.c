// NPC: /d/huashan/npc/mu_renqing.c
// Date: Look 99/03/25
// Modify by Lklv 2001.10.18
#define QUESTDIR "quest/��ɽ��/ӥ��������/"

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_quest1();
string ask_quest2();
string ask_miji();

void create()
{
        set_name("������",({"mu renqing", "mu", "renqing"}));
        set("nickname","����ԯ");
        set("long", "������ڽ���������Զ����������𣬻�ɽ������ԯ�����塣\n");
        set("age", 70);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("per", 26);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 9000);
        set("max_jing", 7800);
        set("eff_jingli", 7500);
        set("max_neili", 16000);
        set("neili", 16500);
        set("jiali", 100);
        set("combat_exp", 4200000);
        set("score", 29000);

        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               (: perform_action, "sword.jianzhang" :),
        }));
        set_skill("sword",  350);
        set_skill("dodge",  350);
        set_skill("force",  360);
        set_skill("cuff", 350);
        set_skill("poyu-quan", 340);
        set_skill("huashan-jianfa", 350);
        set_skill("parry",  360);
        set_skill("literate", 230);
        set_skill("huashan-qigong", 350);
        set_skill("strike", 350);
        set_skill("hunyuan-zhang", 350);
        set_skill("huashan-shenfa", 350);
        set_skill("zhengqi-jue", 200);

        map_skill("dodge", "huashan-shenfa");
        map_skill("force","huashan-qigong");
        map_skill("cuff","poyu-quan");
        map_skill("strike","hunyuan-zhang");
        map_skill("parry","huashan-jianfa");
        map_skill("sword","huashan-jianfa");
        prepare_skill("strike", "hunyuan-zhang");

	set_temp("apply/damage", 80);
        set_temp("apply/dodge", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/armor", 80);
        create_family("��ɽ��",12,"����");

    set("inquiry", ([
         "ӥ������" : (: ask_quest1 :),
         "ӥ��������" : (: ask_quest2 :),
         "�ؼ�" : (: ask_miji :),
        ]));
        setup();
        carry_object(BINGQI_D("sword"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}
void init()
{
     add_action("do_go", "gensui");
     add_action("do_go", "goto");
}


void attempt_apprentice(object ob)
{
        mapping fam;
        if (mapp(fam=ob->query("family")) && (string)fam["family_name"] != "��ɽ��"  && (int)ob->query("is/huashan")==1 ) {
                message_vision(CYN "$N���������ɽ�ɵ���ͽ��������ʲô ������\n"NOR, ob );
                command("slap "+ob->query("id"));
                return;
        }
	if (ob->query("fengset")) {
		command("say �㲻���Ѿ����˷����������˼�Ϊʦ��ô��");
		return;
	}
	        if(ob->query("quest/huashan")=="����"){
                command("heng");
                command("say �ߺߣ����ڵ��������뿪��ɽ�������ǻ�ɽ�ɵ��ӣ�����������ѵ���������������֮λ��");
                return;
        }
        if (ob->query_skill("zixia-gong",1) < 100 ) if(ob->query_skill("huashan-qigong",1)<100 ) {
		command("say �����ϼ����Ϊ̫�ץ�������ɡ�");
		return;
	}
        if ((int)ob->query("shen") <= 0) {
	        command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
	        command("say �ڵ��з��棬" + RANK_D->query_respect(ob)+"�Ƿ����ò�����");
	        return;
        }
        if ((int)ob->query("max_pot") < 230) {
	        command("say " + RANK_D->query_respect(ob)+"���ڲ���Ҫ����ָ������ȥ��������ʦ��ѧ��ȥ�ɡ�");
	        return;
        }
        command("say �ðɣ��Ҿ���������,���ҪΪ���ǻ�ɽ��������������");
        command("recruit " + ob->query("id"));
        ob->set("title",HIW"��ɽ�������״�����"NOR);
        ob->set("quest/huashan","����");
}

string ask_quest1()
{
        mapping fam;
        object me;
        int exp, exp2, i;
        me = this_player();
        exp = (int)me->query("combat_exp", 1);
        exp2 = (int)me->query(QUESTDIR+"combat_exp", 1);
        i = (int)me->query("job_time/��ɽ",1);
        fam = me->query("family");
        
        if (!fam || fam["family_name"] !="��ɽ��")
                return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��\n";

      if (!me->query(QUESTDIR+"������/over"))
        return "�һ�ɽ����λǰ���ۿ�ӥ������������һ��ӥ���������ľ�ѧ��\n";

        if(me->query_temp(QUESTDIR+"start2"))
                return "�Ҳ����Ѿ�����˵������\n";

        if( i < 2000 )
                return "��Ϊ�һ�ɽ�������Ĺ���΢�������ܸ�������Ȼ���Ҫ�£�\n";
         //��ɽ�����������1000�� by daidai

        if(exp2 && exp-exp2 < 200000 && !me->query("cw_exp"))
                return "�㵱ǰ�ľ�����»���������������������ץ��ȥ����ȥ�ɡ�\n";
         //������200k by daidai

        if(me->query(QUESTDIR+"time") && time()-me->query(QUESTDIR+"time")<86400)
                return "����͵�����ɣ������������ɡ�\n";
        
        if(me->query(QUESTDIR+"pass"))
                return "�㲻���Ѿ�������\n";

        if(me->query(QUESTDIR+"fail")>=3 && me->query("registered")<3)
                return "���Ѿ����㽲������ˣ�����Ͳ����Ҵ�Ϊ�μ�����˲��\n";
        me->set_temp(QUESTDIR+"start2", 1);
        me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
        me->set(QUESTDIR+"time",time());
         message_vision(CYN"\n�������������һλ���ˣ�\n"NOR, me);
        return "�������ֺ����ɽ���ﳣ��ӥ�߳�û���һ�ɽ����ʮ��·ӥ������������ǰ������������ۿ�ӥ���භ�иж�����
��������Ȥ�������˴���ȥ��(gensui)��˵���������ջ��أ�\n";
}

string ask_quest2()
{
        mapping fam;
        object me;
        me = this_player();
        fam = me->query("family");

        if (!fam || fam["family_name"] !="��ɽ��")
                return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��\n";

        if(!me->query(QUESTDIR+"over"))
          return "�����һ�ɽ�ɵľ�ѧ���ԴӵھŴ�����ɥ���ڹ�����֮���ʧ���ˣ�ֻ����һ�������ܲ�͸���ؼ��б���\n";
 
        tell_object(me,HIC"\n�㽫�ղ������Լ��Լ��ĸ���һһ�����������塣\n"NOR);
        me->set(QUESTDIR+"pass",1);
        me->delete(QUESTDIR+"over");
        return "��Ȼ��ˣ��������б�ӥ�����������ؼ��б���Ҳ�����ܴ���ѧ���㶫����\n";
}
string ask_miji()
{
        mapping fam;
        object me,book;
	int exp, exp2;
        me = this_player();
        fam = me->query("family");

        if (!fam || fam["family_name"] !="��ɽ��")
                return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��\n";

       if(me->query_temp(QUESTDIR+"������/over"))
                return "���Ѿ��õ��ؼ��ˣ���������ң�\n";

      if(!me->query(QUESTDIR+"������/over")){
                exp = (int)me->query("combat_exp", 1);
                exp2 = (int)me->query(QUESTDIR+"combat_exp", 1);

      if(exp2 && exp-exp2 < 200000)
                return "�㵱ǰ�ľ�����»���������������������ץ��ȥ����ȥ�ɡ�\n";
         //������200k by daidai

        if(me->query(QUESTDIR+"time") && time()-me->query(QUESTDIR+"time")<86400)
                return "����͵�����ɣ������������ɡ�\n";

        if(me->query_temp(QUESTDIR+"start"))
                return "�Ҳ����Ѿ�����˵�������㻹��ȥ��������ͽ����\n";

          me->set_temp(QUESTDIR+"start", 1);
                return "�ؼ��б��ҽ�����ͽ���������ˣ����ں���һ������ȥ����ȡ���ؼ��ɡ�\n";
          
           }
       if(!me->query(QUESTDIR+"pass"))
          return "�ؼ���ʲô�ؼ���������ֻ��һ����ѧ��ƪ����ɿ�����Ŷ��\n";

        book = unew("/d/huashan/npc/obj/yingshe-book.c"); 
        if(!clonep(book)) return "�������ˣ�ӥ�����������ؼ��б��ѱ������������������ˡ�";
         
        if(clonep(book) && book->violate_unique()){
               destruct(book);
               return "�������ˣ�ӥ�����������ؼ��б��ѱ������������������ˡ�";
        }
        book->move(this_player());
        return "�������б���ӥ���������ؼ��б��������û�ȥ�ú����У�������ֱ��ɾ�ѧ��";
}

int do_go(string arg)
 {
      object me;
      me = this_player();
      if(!living(me) ) return 0;
      if(! me->query_temp(QUESTDIR+"start2")) return 0;        
      if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");
      if( !arg || arg != "puren")
        return notify_fail("��Ҫ��˭�߰���\n"); 

         message_vision(CYN"\n����˵�������������ɣ�����Ȼ��������ȥ��$N��æ���ϣ�\n"NOR, me);
          me->move("/d/huashan/ys_houshan");     
        return 1;
}


int accept_object(object who, object ob,object me)
{
        me= this_object();

        if( ob->query("id") != "muxia"){
                command("say ������ⶫ������");
                return 0;
        }
        if( ob->query("owner") != who->query("id")
         || !who->query_temp(QUESTDIR+"������/over")){
                command("haha");
                command("say ��л"+RANK_D->query_respect(who) + "�������ؼ��һأ�̫��л�ˡ�");
                who->delete_temp("limochou");
                call_out("dest", 1, ob);
                return 1;
        }
        command("say ̫���ˣ������ڰ��Ȿ�ؼ��б�ȡ�����ˡ�");

            command("say ����������������ɽ��ӥ��֮������֪��.......");
        who->set(QUESTDIR+"������/over", 1);
        who->delete_temp(QUESTDIR+"������/over");
        call_out("dest", 1 ,ob);
        return 1;
}

void dest(object obj)
{
        if(! obj) return;
        destruct(obj);
}

