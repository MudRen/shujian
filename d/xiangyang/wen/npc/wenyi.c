// /d/city/npc/wenyi

#include <ansi.h>
inherit NPC;

int ask_xia1();
string ask_gift();
#define this_quest_is_open "yes"
 
void create()
{
        object ob;
        object sb;
        set_name("����", ({ "wen yi", "wen" }));
        set("long", 
        "�����ǽ����ɾ����������ǡ�\n"
        "һλ��ʮ�����Ů�ӣ���ò���㣬����һ�ֳ������ζ��\n");
        set("gender", "Ů��");
        set("age", 36);
        set("attitude", "friendly");
        set("shen", 1000);
        set("str", 35);
        set("int", 30);
        set("con", 25);
        set("dex", 27);
        
         set("max_qi", 999999);
         set("max_jing", 999999);
         set("max_neili", 999999);
         set("neili", 999999);
        set("jiali", 10);
        set("combat_exp", 5000);
         

    set_skill("force", 10);
    set_skill("yijin-jing", 10);
    set_skill("dodge", 10);

    set_skill("shaolin-shenfa", 10);
    set_skill("cuff", 10);
    set_skill("wenjia-daofa", 10);
    set_skill("parry", 10);
    set_skill("blade", 10);
    set_skill("wenjia-quan", 10);
    set_skill("literate", 10);

          map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("cuff", "wenjia-quan");
        map_skill("parry", "wenjia-daofa");
        map_skill("blade", "wenjia-daofa");
    prepare_skill("cuff", "wenjia-quan");
    
    set("inquiry", ([
                "������" : "��������Ů��,������,��������.\n",
                "������" : "��������Ů��.\n",
                "�·�ɽ" : "�·�ɽ���ҵ���.\n",
                "�����ɾ�" : "�������µĽ����ɾ������ҵķ����\n",
                "�¼�����" : "��......\n",
                "��ѩ��" : (: ask_xia1 :),
                "����" : (: ask_gift :),
                "�Ʒ��ؼ�" : (: ask_gift :),
                "�����Ʒ�" : (: ask_gift :),
        ]));
 
        setup(); 
        
        if (clonep()) {
                ob = unew("/d/xiangyang/wen/quest/obj/jszf-book");
                if (!ob) ob = new("/clone/money/gold");
                ob->move(this_object());
                sb = unew("/d/xiangyang/wen/quest/obj/gift");
                if (!sb) sb = new("/clone/money/gold");
                sb->move(this_object()); 
                
          carry_object(ARMOR_D("flower_shoe"))->wear();
    carry_object(ARMOR_D("pink_cloth"))->wear();

        }
         
     
}

void init()
{
        add_action("do_comfort", "comfort");
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        message_vision("���Ƕ�$N����һЦ����ת����ȥ��ü���û��˿���־塣��\n", ob);
        message_vision("$N���к�Ȼ���ã����Լ����������޳ܣ���һ�����޴�������ҲҪ�´˶��֣���\n", ob);
}

int ask_xia1()
{
        object me = this_player();
        string msg;
        msg = CYN"��������$N��ѯ��,����һ��,��ɫ��䡣\n"NOR;
        message_vision(msg, me);
                
    if (me->query_temp("quest/�����Ʒ�/start",1)) {
        remove_call_out("do_happen1");
        call_out("do_happen1",3,me);
                return 1;
        }
        msg = CYN"������ɫ���˼���,����ƽ������,��$N˵:��������ʲô?\n"NOR;
        message_vision(msg,me);
        me->set_temp("quest/jinshe2/fail",1);
        return 1;
}

int do_happen1(object me)
{
        string msg;
        //if (base_name(environment(me)) != HERE)               return 1;
        msg = CYN"����̾�˿���,��:��Ȼ�������������,�Ҿ͸�����ɡ�\n"NOR;
        msg+= CYN"���Ƕ��˶ٵ�:����һ�γ������,ʮ����ǰ������������ĸ�����ѩ��,Ҳ���ǽ����ɾ���\n"NOR;
        msg+= CYN"���ǵ�:���������మ,����Ϊ,����Ϊ��Ŀ��Ի��⸸���ĳ��,���ǵ���......��\n"NOR;
        msg+= CYN"����ͻȻ��Ȧ����,������˵��������......\n"NOR;
        msg+= HIG"���ǿ޵��滨����,��������,���̲�ס��"HIC"��ο(comfort)"HIG"��һ��.\n"NOR;
        message_vision(msg, me);
         me->set("quest/jinshe2/step1",1);
        return 1;       
    }
int do_comfort(string arg)
{
       string msg;
       object me=this_player();
       if( !this_player()->query("quest/jinshe2/step1") )  return 0;
        
        if( !arg ) return notify_fail("��˵ʲô��\n");
        
        message_vision("$N������ο����" + arg + "\n", this_player());
        if( strsrch(arg, "�ķ���") >=0 && (strsrch(arg, "����ѹ�") >=0
         || strsrch(arg, "�ǽ����ɾ�") >=0 || strsrch(arg, "��������������") >=0 )) {
                command("ah");
                command("say ��˵�Ķ������?!!!\n");
                command("touch " + this_player()->query("id"));
                this_player()->set_temp("quest/jinshe2/step2",1);
                this_player()->delete_temp("quest/jinshe2/step1",1);
                return 0;
        } else {
                command("say �����������,�������������,һ�߾���ʮ����.");
                msg = HIC"��ο���ܵ��и��ƺ�,˵��,��Ϣ�����ɰɣ�\n"NOR;
                message_vision(msg, me);
        }
        
        }

int accept_object(object who, object ob)
{
    string msg;
    object me = this_player();
        if( !who || environment(who) != environment() ) {return 0;}
        if ( !objectp(ob) ) {return 0; }
        if ( !present(ob, who) ) return notify_fail("��û�����������\n");
        if ( !this_player()->query_temp("quest/jinshe2/step2")&& !this_player()->query("quest/jinshe2/xin")) return 0;
        if (userp(ob)) {
               command("? " + who->query("id"));
               command("say ����˴������ʲô��");
               this_object()->kill_ob(who);
               return notify_fail("��⣬�����ˣ�\n");
        }
        if(ob->query("id") == "xin jian" && ob->query("name") == "����"){
                if(this_player()->query("quest/jinshe2/xin")) {
                        command("wuwu");
                        command("say ��...����ѩ�˵����塣");
                        command("touch" + who->query("id"));
                        command("say ѩ�˴�ǰ������һ������,���㵱����л��!"); 
                        this_player()->set("quest/jinshe2/gift",1);
                        call_out("destroying", 1, ob);
                        return 1; 
            }
            command("hmm");
            command("say ���Ǵ�����õ��������?������ȥ����Ӱ�ٱ���!");
            msg = HIG"������üһ��:���˰�,�����ƭ�Ӻ��ȥ!!!��\n"NOR;
            message_vision(msg, me);
            message_vision(HIR"\nһȺ�Ҷ�Ӧ������,��$N�Ұ�����,���˳�ȥ��\n"NOR,me);
            me->unconcious();
            me->move("/d/city/chmiao");
            tell_room(environment(me),HIR"ͻȻӿ��һȺ�¸��Ҷ�,��" + me->name(1) +"�ҹ�����,���˳�ȥ"NOR);
            return 1;
          }
        if ((string)ob->query("name") != HIY"����׶"NOR || ob->query("id") != "jinshe zhui"){
               command("shake "+ (string)who->query("id"));
               command("say лл������");
               return 0;
        }
        if( !this_player()->query_temp("quest/���߽���/����׶"))
        {
             command("hmm");
              command("say ���Ǵ�����õ���?������ȥ����Ӱ�ʹ���ٱ���!");
             msg = HIG"������üһ��:���˰�,�����ƭ�Ӻ��ȥ!!!��\n"NOR;
             message_vision(msg, me);
             message_vision(HIR"\nһȺ�Ҷ�Ӧ������,��$N�Ұ�����,���˳�ȥ��\n"NOR,me);
             me->unconcious();
             me->move("/d/city/chmiao");
             tell_room(environment(me),HIR"ͻȻӿ��һȺ�¸��Ҷ�,��" + me->name(1) +"�ҹ�����,���˳�ȥ"NOR);
         call_out("destroying", 1, ob);
             return 1;
}
        command("ah "+(string)who->query("id"));
        command("say ����ѩ�˵�����֮��,�����������и�����,���������"HIY"��Ϣ"CYN"�Ļ�,�鷳����������һ��.\n"NOR);
        command("thank "+(string)who->query("id"));
        msg = HIG"������������й���ѩ�˵�"HIW"��Ϣ"HIG",ȥ������ѩ�˵�"HIR"����"HIG"����ʲô�����ɡ�\n"NOR;
        message_vision(msg, me);
        who->set("quest/jinshe2/xin", 1);
        who->delete_temp("quest/jinshe2/step2",1);
        call_out("destroying", 1, ob);
        return 1;
}
void destroying(object ob)
{
        if (!ob) return;
        if (userp(ob)) command("drop "+ob->parse_command_id_list()[0]);
        else destruct(ob);
}

string ask_gift()
{
        object ob, sb,me = this_player();
        mapping quest;
        int time;
  
  if ( !me->query("quest/jinshe2/pass") && !me->query("quest/jinshe2/gift"))
        return "Ү?����ôͻȻ˵��ô��ֵ�����?\n";
        
        if ( is_busy() || is_fighting())
                return "��û��������æ��ô��\n";
  
        sb = present("box", this_object());
  ob = present("zhangfa miji", this_object());
        if ( !ob && !sb)
                return "Ү���������ҷŵ�����ȥ�ˣ�\n";

        time = time() - me->query("quest/jinshe2/zf_time");
        if ( me->query("quest/jinshe2/zf_time") && time < 86400 && !wizardp(me) &&  !me->query("env/debug"))
                return "�㲻���Ѿ��ʹ���?����̰������!!!\n";

        quest = me->query("quest/jinshe2");

        if ( quest["pass"] ) {
                if ( ob ) {
                        ob->set("owner", me);
                        ob->move(me);
                        me->set("quest/jinshe2/zf_time", time());
                        return "�ðɣ��Ȿ���Ʒ�ͼ�⡹���û�ȥ�ú��о��о���\n";
                }
                else
                        return "��Ҫ�ġ��Ʒ�ͼ�⡹�Ѿ�������������\n";
        }
        if ( quest["gift"] ) {
                if ( sb ) {
                        sb->set("owner", me);
                        sb->move(me);
                        me->set("quest/jinshe2/zf_time", time());
                        return "лл��,�ҷ����µ���������������͸����.\n";
                }
                else
                        return "�治��,����������û��,�������������.\n";
        }

        if ( me->query("registered")< 3 )
                return "�����ں�æ��û��Ȥ��������£�\n";

}
