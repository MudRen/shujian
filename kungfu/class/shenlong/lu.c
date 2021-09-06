//Cracked by Roath
//  lugaox.c  ½����

inherit NPC;
// inherit F_MASTER;

string ask_jieyao();
string ask_sheyao();
string ask_huang();
string ask_book();
void apply_gift(object, int);

string *lujob = ({
        "/d/shenlong/obj/fengchao",
        "/d/shenlong/obj/hougan",
});

void create()
{
        set_name("½����", ({ "lu gaoxuan","lu" }));
        set("long",
                "��ʮ������ͣ���ʿ��磬����Ͱ����ס�\n");
        set("gender", "����");
        set("age", 41);
        set("attitude", "peaceful");

        set("shen_type", -1);
        set("score", 50000);
        set("shen", -15000);

        set("str", 36);
        set("int", 30);
        set("con", 28);
        set("dex", 30);

        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jingli", 1500);
        set("max_jingli", 1500);
        set("jiali", 60);
        set("combat_exp", 160000);

        set_skill("force", 100);
        set_skill("dulong-dafa", 80);
        set_skill("dodge", 100);
        set_skill("lingshe-shenfa", 80);
        set_skill("strike", 80);
        set_skill("huagu-mianzhang", 80);
        set_skill("parry", 120);
        set_skill("sword", 100);
        set_skill("medicine", 80);
        set_skill("literate", 90);
//      set_skill("digging", 100);
//      set_skill("magic", 50);
//      set_skill("shenlong-magic", 50);

        set_temp("apply/attack", 60);
        set_temp("apply/damage", 40);
        set_temp("apply/dodge", 50);

        map_skill("force", "dulong-dafa");
        map_skill("dodge", "lingshe-shenfa");
        map_skill("strike", "huagu-mianzhang");
        map_skill("parry", "huagu-mianzhang");
//      map_skill("magic", "shenlong-magic");

        prepare_skill("strike", "huagu-mianzhang");

        create_family("������", 2, "����");
        set("inquiry", ([
                "��ҩ" : (:ask_jieyao:),
                "�����׽���" : (:ask_jieyao:),
                "ҽ��" : (: ask_book :),
                "yishu"  : (: ask_book :),
                "��ҩ" : (: ask_sheyao :),
                "�ۻ�" : (: ask_huang :),
        ]));

        set("chat_chance", 5);
        set("chat_msg", ({
                "½������������������һ���軪ɽ��һ�����ϵȷ䳲��\n",
                "½������������������ɽ��ֻǧ��ﾫ��֪����û�С�\n",
        }) );

        set("book1_count", 1);
        set("book2_count", 1);
        set("book3_count", 1);

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if( (int)ob->query_temp("mark/½") < 1 )
                return 0; 
        ob->add_temp("mark/½", -1);
        return 1;
}

string ask_huang()
{
        object ob, me = this_player();

        if( !me->query("sg/spy") ) 
                return RANK_D->query_respect(me) +
                "�뱾��������������֪�˻��Ӻ�̸��";

        if(  present("xionghuang", me) )
                return RANK_D->query_respect(this_player()) + "���������ϲ����������ô����Ҫ�ˣ�����̰�����У�";

        if( time() < me->query("huang/time") + 1800 )
                return RANK_D->query_respect(me) + "�㲻�Ǹ�Ҫ���ۻƣ���ô����Ҫ�ˣ�����ʱ�������ɡ�";

        me->set("huang/time", time()); 
        ob = new("/d/shenlong/obj/xionghuang");
        ob->move(me);
        return "�ðɣ�����ۻ������ȥ�ɡ�";
}

string ask_sheyao()
{
        object me = this_player();

        if( !me->query("sg/spy") ) 
                return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";

        if( !me->query_condition("snake_poison") )
                return"��úõģ�Ҫ��ҩ����";

        if( me->query("gender") == "����" )
                say("�ٺ٣���û��Ϣ��Ϊ�˷�������������Ҫ�ˣ�\n");
        else    say("̾���ǲ��Ƿ��������������ˣ�\n");

        message_vision("$N��$n˵���������ſ���\n", this_object(), me);
        message_vision("$N�����ŵô��ġ�\n", me);
        message_vision("ֻ��$N��һ����ҩȫ����$n����\n", this_object(), me);
        message_vision("$N�ֲ���֧�ض�$n˵������л½���\n", me, this_object()
);

        call_out("lucure", 1 + random(2), me);
        return "�´�С���ˡ�";
}

void lucure(object me)
{
        message_vision("$N�³�һ�ں�Ѫ����ɫ������������ˡ�\n", me);
        me->clear_condition("snake_poison");
}

string ask_jieyao()
{
        object ob, me = this_player();

        if( !me->query("yijin_wan") )
                return "��ҩ��ô������ҳԣ�\n";
/*
        if( (int)me->query("combat_exp") < 100000 )
                return "ƾ�������У�Ҳ�������ӽ�ҩ��\n";
*/
        if( (int)me->query_temp("lu/jieyao") )
	        return "��û���ҵ�ʶ�ü׹��ĵ��мң�\n";

        command("sigh");
        say("½����˵����Ҫ�������޶������ڽ�����������뿪�������ˡ�\n");

        ob = new("/d/shenlong/obj/zihua");
        ob->move(me);
        me->set_temp("lu/jieyao", 1);
        message_vision("$N��һ" + ob->query("unit") + ob->query("name") + "����$n��\n", this_object(), me);
        return "������ܷõ�һλʶ�ü׹��ĵ��мҽ�����������Ҿ͸����ҩ��\n";
}

string ask_book()
{
        object ob, *obs, me = this_player();
        int lvl;
        
        if( !me->query("yijin_wan") )
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";

        if( (int)me->query("sg/exp") < 1000 )
                return "��ƾ" + RANK_D->query_respect(this_player()) + "�ڽ��еı��֣�ҽ��֮�¾���̸�ˡ�";

        lvl = me->query_skill("medicine", 1);

        if( lvl < 30 ) {
                if( query("book1_count") < 1 )
                        return "�������ˣ�������Ҫ��ҽ���Ѿ����������ˡ�";
                obs = filter_array(children("/d/shenlong/obj/yijing1.c"), (: clonep :));
                if( sizeof(obs) )
                        return "�������ˣ�������Ҫ��ҽ���Ѿ����������ˡ�";
                ob = new("/d/shenlong/obj/yijing1");
                ob->move(me);
                add("book1_count", -1);
                return "�ðɣ��Ȿ���Ƶ��ھ������û�ȥ�ú����С�";
        } else if( lvl < 60 ) {
                if( query("book2_count") < 1 )
                        return "�������ˣ�������Ҫ��ҽ���Ѿ����������ˡ�";
                obs = filter_array(children("/d/shenlong/obj/yijing2.c"), (: clonep :));
                if( sizeof(obs) )
                        return "�������ˣ�������Ҫ��ҽ���Ѿ����������ˡ�";
                ob = new("/d/shenlong/obj/yijing2");
                ob->move(me);
                add("book2_count", -1);
                return "�ðɣ��Ȿ��ʮ�ľ����ӡ����û�ȥ�ú����С�";
        } else if( lvl < 90 ) {
                if( query("book3_count") < 1 )
                        return "�������ˣ�������Ҫ��ҽ���Ѿ����������ˡ�";
                obs = filter_array(children("/d/shenlong/obj/yijing3.c"), (: clonep :));
                if( sizeof(obs) )
                        return "�������ˣ�������Ҫ��ҽ���Ѿ����������ˡ�";
                ob = new("/d/shenlong/obj/yijing3");
                ob->move(me);
                add("book3_count", -1);
                return "�ðɣ��Ȿ����˼��ǧ�𷽡����û�ȥ�ú����С�";
        }

        return "������֪ҽ�������û�к��ʵ�ҽ���ɹ������С�";
}

int accept_object(object who, object ob)
{
        mapping my;
        int i, tot, bonus;

        if( who->query_temp("lu/jieyao") && ob->name() == "�̴�" ) {
                who->delete("yijin_wan");
                my = who->query_entire_dbase();
                tot = my["str"] + my["int"] + my["con"] + my["dex"];
                tot -= 80;
                if( tot > 0 ) {
                        for(i = 0; i < tot; i ++) {
                                switch (random(4)) {
                                        case 0: my["str"]--; break;
                                        case 1: my["int"]--; break;
                                        case 2: my["con"]--; break;
                                        case 3: my["dex"]--; break;
                                }
                        }
		}
                            
                who->delete("sg");
                who->delete("sgjob");
                who->set("sg/cured", 1);
                who->delete("yijin_wan");
                apply_gift(who, 0);

                command("touch " + who->query("id"));
                message_vision("½�������´����ͳ�һ��ҩ��������$N�����\n", who);
                command("whisper " + who->query("id") + " " + "���¿�ǧ���������ȥ��\n");

                call_out("destroy", 1, ob);
                return 1;
        }

        if( member_array(base_name(ob), lujob) == -1 )
                return 0;

        command("nod");
        call_out("destroy", 1, ob);

        if( ob->query("owner") != who->query("id") ) {
                command("say �ǣ��ǣ��ǣ���������ü���һ" + ob->query("unit") + ob->query("name") + "��");
                return 1;
        }

        if( (bonus = who->query("combat_exp")) > 100000 ) {
                command("say ����С���Ժ�Ͳ���������ˡ�");
                return 1;
        }

        if( random(6) )
        who->add("sg/exp", 1);

        bonus = 50 + (100000 - bonus) / 200;
        who->add("combat_exp", bonus + random(bonus));
        who->add_temp("mark/½", bonus/10);
        return 1;
}

void destroy(object ob)
{
        destruct(ob);
}

void apply_gift(object me, int flag)
{
        int i;
        int tmpstr, tmpint, tmpcon, tmpdex;
        mapping my = me->query_entire_dbase();

        tmpstr = tmpint = tmpcon = tmpdex = 10 + flag;

        for (i = 0; i < 40; i++) {
                switch (random(4)) {
                        case 0: tmpstr++; break;
                        case 1: tmpint++; break;
                        case 2: tmpcon++; break;
                        case 3: tmpdex++; break;
                }
        }

        if (tmpstr <= 30) my["str"] = tmpstr;   else my["str"] = 30;
        if (tmpint <= 30) my["int"] = tmpint;   else my["int"] = 30;
        if (tmpcon <= 30) my["con"] = tmpcon;   else my["con"] = 30;
        if (tmpdex <= 30) my["dex"] = tmpdex;   else my["dex"] = 30;
}

