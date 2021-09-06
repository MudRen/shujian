// npc: /d/city/npc/wei.c
// Jay 5/15/96
// Modify by Linux@sj ����ask ΤС����ַ

#include <get_place.h>
inherit NPC;
string ask_beauty();
string ask_me();
void create()
{
        set_name("Τ����", ({ "wei chunfang", "chunfang", "wei" }) );
        set("gender", "Ů��" );
	set("title", "����Ժ�ϰ���");
        set("age", 42);
        set("long", 
            "Τ�����ǵ���¹������컨���ܶ���ΤС�����������"
	    "����ϣ��������ȴ档\n");
        set("str", 65);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
	set("per", 18);
        set("shen_type", 1);
        set("no_get","Τ�����������̫���ˡ�\n");

	set_skill("force", 20);

        set("combat_exp", 200);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "�����Ҿ���Τ������",
            //"ΤС��" : "�����ҵĹԶ���, һ˫�۾��������Ǹ�����, �����е�����Ǹ����ӡ�",
            "ΤС��" : (: ask_me :),
            "wei xiaobao" : (: ask_me :),
            "����Ժ" : "��������Ժ�������ݳ���ͷһ�ݵ�������ȥ����",
            "here" : "��������Ժ�������ݳ���ͷһ�ݵ�������ȥ����",
            "beauty" : (: ask_beauty :),
       	]) );

        setup();
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                "Τ���������˵�������������ұ��µúܣ�ÿ���кü������ˡ�\n",
                "Τ����ŭ������������裬Ҫ����ɲ����ë���ӵ�����Ժ���������ô�ɨ�����˳�ȥ���\n",
                "Τ��������˵������һ˫�۾���߯�����ģ������Ǹ����\n",
        }) );
        carry_object("/d/city/obj/flower_shoe")->wear();

        carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (base_name(environment()) != query("startroom")) return;
        if (interactive(ob = this_player()) && visible(ob) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
string ask_me()
{
       object ob, where;
       object me = this_player();
       ob = find_living("wei xiaobao");
       if (!ob) return "���С�����ӣ�������Ҳ��֪����ȥ�����ˡ�\n";
       where = environment(ob);
       if (!where) return "���С�����Ӻ�����ʧ��Ү...\n";  
       if (objectp(present("wei xiaobao", environment(me)))){
          	command("disapp "+me->query("id"));
          	return "�Ҷ��Ӿ�������ѽ...\n";   
       }
       command("look "+me->query("id"));
       return "��λ" + RANK_D->query_respect(me) + "��������˵�����ǹԶ�������" + get_place(base_name(where)) + (string)where->query("short") +"�������ء�";
}
void greeting(object me)
{
	if (!me)
		return;
    	command("look " + me->query("id"));

    	if (me->query("gender")=="����") {
       	command("say �㵱��������������������裬���������ɲػض��ӣ����ǲ��ź�̫�࣡");
       	command("kick " + me->query("id"));
       	message("vision", me->name() +"��Τ����һ���߳����⡣\n",
                environment(me), ({me}));
       	me->move("/d/city/nandajie2");
       	message("vision", me->name() +"���˴�����Ժ�����˳������Ե��ڵ��ϣ��ĵ�����������\n", 
                environment(me), ({me}));

    	}
    	else {
    		if (me->query("class") =="bonze") {
       		command("say �ϣ�" + RANK_D->query_respect(me) 
			+"Ҳ�������������Ժ����");
       		command("say �뵱���ҽӹ�һ������������ϴ�ǰһ��Ҫ���һ����������Ӿ͹�����������ҡ�");
		}
    		if (me->query("gender")=="Ů��") {
       		command("say ��ѽ�������´����Ҳ��Ҥ�ӣ��ɺ���ͳ��");
       		command("sigh");
       		command("say ��ϧ�Ҷ��Ӳ��ڣ���Ȼ�����ź��㡣");
    		}
    	command("say ¥��¥�µĹ����ǣ��������ˣ�");
    	}
    	return ;
}

string ask_beauty()
{
	object where,obj,*ob_list;
	string msg, name;
	int i, per = 0;

//	ob_list = sort_array(users(), (: env_cmp :));
	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("per") > per 
		&& ob_list[i]->query("gender") == "Ů��"
		&& !ob_list[i]->query("hooker")
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			per = obj->query("per");
		}
	}

	if ( !obj ) {
	msg ="���ģ����ھ�Ȼһ������Ҷ�û�У��϶���������������å�����ˣ�\n";
	return msg;
	}

	name = obj->query("name")+"("+obj->query("id")+")";
	switch( per/5 )
	{
	case 0:
	case 1:
	case 2:
		msg ="�����齣���Ȼ��"+name+"�����������ˣ��߷�����ĸҹ����Ư�����⻹��������\n";
		break;
	case 3:
		msg =name+"����ò����������֮�ʣ���ô�����������أ������ɽ�����ϻ������ӳư����ɣ�\n";
		break;
	case 4:
		msg =name+"����ò�����������ھ������ˣ��Ͽ�����Ҹ��Ϲ����˰ɣ�\n";
		break;
	case 5:
		msg =name+"�����Ǹ��������������������Ժ���ӿͣ��Թ����Ķ��²˳���У����ܿ���̤���ſ��ӣ�\n";
		break;
	case 6 :
		msg =name+"������Ů�·��ɣ����������Ժ�ӣ�����������Ҳ������ĳ����أ�\n";
		break;
	}

	return msg;
}
