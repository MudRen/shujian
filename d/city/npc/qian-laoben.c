//by xiaoyao

inherit NPC;

string ask_degree();
string ask_food();
string ask_pighead();
string ask_highhand();
string ask_pigexp();

void create()
{
    set_name("Ǯ�ϱ�", ({ "qian laoben", "qian" }) );
    set("gender", "����" );
    set("age", 47);
    set("long", 
   "����������ػṰ���һ���֣������Ѿ��뿪��̳�����ˡ�\n");

    set("shen_type", 1);

    set("attitude", "heroism");
    set("inquiry", ([
        "�ɼ�" : "�� pigscore ���Բ��Լ�����͵���ͷ�Ĵ�����\n",
        "pigscore" : "�� pigscore ���Բ��Լ�����͵���ͷ�Ĵ�����\n",
        "����" : "help pig_cmds ������й����help pig_rules ����pigscore �ɼ���\n",
        "�����" : (:ask_degree:),
        "rank" : (:ask_degree:),
        "�Ե�" : (: ask_food :),
        "food" : (: ask_food :),
        "pighead" : (: ask_pighead :),
        "��ͷ" : (: ask_pighead :),
        "highhand" : (: ask_highhand :),
        "����" : (: ask_highhand :),
        "pigexp" : (: ask_pigexp :),
        "����" : (: ask_pigexp :),
    ]));

    setup();
    carry_object("/d/city/npc/obj/niupi")->wear();
    carry_object("/clone/weapon/tieguo")->wield();
}

void init()

{
    object me = this_player();

    add_action("do_check", "pigscore");
    add_action("do_clearpig", "��Ҫ����Ŀǰ�Ĺ���ɼ���");

    ::init();
    if (interactive(me = this_player())) {
        remove_call_out("greeting");
        call_out("greeting", 1, me);
    }
}

string ask_degree()
{
     object me = this_player();

    int pighead = (int)me->query("pig_new/head");
    int pigmade = (int)me->query("pig_new/pig_made");

    string title,newtitle;
    int index,level;

    title = me->query("title");
    if (title) {
        index = strsrch(title,"��");
        if (index>1) 
            title = title[0..(index-1)];
        else if (index!=-1)
            return ("��ĳƺ�̫�֣���û���ġ�\n");
    }
    me->set("title",title);

    level = (pigmade-pighead)*(pigmade+1)/(pighead+1);

    if (level < 1 ) newtitle = "����";
    else if (level < 4) newtitle = "ѧͯ";
    else if (level < 9) newtitle = "ͯ��";
    else if (level < 16) newtitle = "����";
    else if (level < 25) newtitle = "���";
    else if (level < 36) newtitle = "����";
    else if (level < 49) newtitle = "��Ԫ";
    else if (level < 64) newtitle = "��ʿ";
    else if (level < 81) newtitle = "��Ԫ";
    else if (level < 100) newtitle = "��ʿ";
    else if (level < 121) newtitle = "����ʿ";
    else if (level < 144) newtitle = "����";
    else if (level < 169) newtitle = "̽��";
    else if (level < 196) newtitle = "����";
    else if (level < 225) newtitle = "״Ԫ";
    else if (level < 256) newtitle = "����";
    else if (level < 289) newtitle = "ѧʿ";
    else if (level < 324) newtitle = "��ѧʿ";
    else if (level < 361) newtitle = "�׸�";
    else if (level < 400) newtitle = "����";
    else if (level < 500) newtitle = "����ʦ";
    else newtitle = "����";

    if (title && title!="") title = title+"�������" + newtitle;
    else title = newtitle;

    title = title + " " + me->query("name") + 
        "(" + capitalize(me->query("id")) + ")";
    me->set_temp("apply/short", ({title}));

    return "ƾ���µĹ����飬���Ϸ򿴣��������������"+newtitle+"��\n";
}

int do_check()
{
    object me = this_player();
    int pigplayed = (int)me->query("pig_new/played");
    int pighead = (int)me->query("pig_new/head");
    int pigmade = (int)me->query("pig_new/pig_made");
    int score = (int)me->query("pig_new/score");

    write("������ " + pigplayed +  " �ι������� " +
        pigmade + " ����ͷ������� " + pighead + " ����ͷ���ܷ� " + 
        score + " �֡�\n");


    return 1;
}


void greeting(object me)
{
    int total = (int)me->query("pig_new/played");
    int pighead = (int)me->query("pig_new/head");
    int score = (int)me->query("pig_new/score");
    int pigmade = (int)me->query("pig_new/pig_made");
    string newtitle;
    int level;

        switch(random(9)) {
        case 1:
        command("pig " + me->query("id"));
                break;

        case 2:
            if (total == 0) 
                        command("say �㿴���ӻ��Ǹ���̳���ְɡ�");
        else if (total > 100) 
            command("say ������治�ٰ���");
          else 
                        command("pig " + me->query("id"));
                break;

        case 3:
        if (total > 100) 
            command("courage " + me->query("id"));
                else 
                        command("pig " + me->query("id"));
                break;

        case 4:
        if (total * (-100 ) < score) 
            command("say ����ö࣬�����٣������ģ�");
        else if (pighead>0) 
            command("say �棬����ô����" + 
                CHINESE_D->chinese_number(pighead) + "����ͷ��");
                break;

        case 5:
        if (pighead>0) 
            command("say �棬����ô����" + 
                CHINESE_D->chinese_number(pighead) + "����ͷ��");
                command("laugh " + me->query("id"));
                break;
        case 6:
        command("welcome " + me->query("id"));
                break;
                
        case 7:
        command("touch " + me->query("id"));
                break;
         
        case 8:
        command("hoho " + me->query("id"));
                break;
        
        
         

        default:
        level = (pigmade-pighead)*(pigmade+1)/(pighead+1);

        if (level < 1 ) newtitle = "����";
        else if (level < 4) newtitle = "ѧͯ";
        else if (level < 9) newtitle = "ͯ��";
        else if (level < 16) newtitle = "����";
        else if (level < 25) newtitle = "���";
        else if (level < 36) newtitle = "����";
        else if (level < 49) newtitle = "��Ԫ";
        else if (level < 64) newtitle = "��ʿ";
        else if (level < 81) newtitle = "��Ԫ";
        else if (level < 100) newtitle = "��ʿ";
        else if (level < 121) newtitle = "����ʿ";
        else if (level < 144) newtitle = "����";
        else if (level < 169) newtitle = "̽��";
        else if (level < 196) newtitle = "����";
        else if (level < 225) newtitle = "״Ԫ";
        else if (level < 256) newtitle = "����";
        else if (level < 289) newtitle = "ѧʿ";
        else if (level < 324) newtitle = "��ѧʿ";
        else if (level < 361) newtitle = "�׸�";
        else if (level < 400) newtitle = "����";
        else if (level < 500) newtitle = "����ʦ";
        else newtitle = "����";

                if (level < 1 )
                        command("say �㻹�Ǹ��������ְ���");
                else 
                        command("say ����"+ newtitle + "��������");
                break;
        }
    return;
}

string ask_food()
{

    return "��Ͽ�ȥ������������ͷ����ҷ��ųԡ�";
}


int do_clearpig()
{
    object me = this_player();
    int pigplayed = (int)me->query("pig_new/played");
    int pighead = (int)me->query("pig_new/head");
    int pigmade = (int)me->query("pig_new/pig_made");
    int score = (int)me->query("pig_new/score");

    if (pigplayed < 50) 
        write("��ľ��黹���㣬�๰���Σ����ܻ��н�����\n");

    else {
        me->add("pig_old/played", pigplayed);
        me->add("pig_old/head", pighead);
        me->add("pig_old/pig_made", pigmade);
        me->add("pig_old/score", score);

        me->delete("pig_new/played");
        me->delete("pig_new/head");
        me->delete("pig_new/pig_made");
        me->delete("pig_new/score");

        message_vision("$N�����������ĵ���Ǯ�ϱ�����˵�˼��仰��\n", me);
        message_vision("Ǯ�ϱ���������ס$N��˫�֣�Ŭ���ɣ���һ����ɹ��ģ�\n", me);
        write("��Ĺ���ɼ�ȫ������ˡ�\n");
    }
    return 1;
}

string ask_pighead()
{
        object where,obj,*ob_list;
        string msg, name;
        int i, pighead = 0;

        ob_list = users();

        for( i = 0; i < sizeof(ob_list); i++) {
                where = environment(ob_list[i]);
                if( ob_list[i]->query("pig_new/head") > pighead 
                && where
                && strsrch(file_name(where), "/d/") >= 0) {
                        obj = ob_list[i];
                        pighead = obj->query("pig_new/head");
                }
        }

        if ( !obj ) {
                msg ="�ף�����û�˳Թ���ͷ��\n";
                return msg;
        }

        obj->set_temp("mostpigs",1);
        name = obj->query("name")+"("+obj->query("id")+")";
        msg ="�����������齣����"+name+"�Ե���ͷ��ࡣ\n";

        return msg;
}

string ask_highhand()
{
        object where, obj, *ob_list;
        string msg, name;
        int i, highrank = 0, mypighead, mypigmade, mypigrank;

        ob_list = users
();

        for( i = 0; i < sizeof(ob_list); i++) {
                where = environment(ob_list[i]);
                mypighead = (int)ob_list[i]->query("pig_new/head");
                mypigmade = (int)ob_list[i]->query("pig_new/pig_made");
                mypigrank = (mypigmade-mypighead)*(mypigmade+1)/(mypighead+1);
                if( mypigrank > highrank 
                && where
                && strsrch(file_name(where), "/d/") >= 0) {
                        obj = ob_list[i];
                        highrank = mypigrank;
                }
        }

        if ( !obj ) {
                msg ="�ף�����ȫ�ǹ������ְ���\n";
                return msg;
        }

        obj->set_temp("pighighhand",1);
        name = obj->query("name")+"("+obj->query("id")+")";
        msg ="�������������齣��Ĺ��������"+name+"��\n";

        return msg;
}


string ask_pigexp()
{
        object where, obj, *ob_list;
        string msg, name;
        int i, pigexp = 0, mypigexp;

        ob_list = users();

        for( i = 0; i < sizeof(ob_list); i++) {
                where = environment(ob_list[i]);
                  mypigexp = (int)ob_list[i]->query("pig_played") 
                        + (int)ob_list[i]->query("pig/played")
                        + (int)ob_list[i]->query("pig_old/played")
                        + (int)ob_list[i]->query("pig_new/played");
                if( mypigexp > pigexp 
                && where
                && strsrch(file_name(where), "/d/") >= 0) {
                        obj = ob_list[i];
                        pigexp = mypigexp;
                }
        }

        if ( !obj ) {
                msg ="�ף�����ȫ�ǹ������ְ���\n";
                return msg;
        }

        obj->set_temp("pighighexp",1);
        name = obj->query("name")+"("+obj->query("id")+")";
        msg ="�������������齣��Ĺ�����������"+name+"��\n";

        return msg;
}
