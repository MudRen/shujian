// been job_npc
string ask_xunluo()
{
        mapping fam; 
        int i;
        object ob, me;
        me = this_player();
        ob = this_object();
        i = ob->query("xl");

        if(!(fam = me->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(me)+"����˵дʲô����";    
        if(ob->query_temp("xl_waiting"))
                return "�ȵȣ������ڼ���ء�";    
        if(!me->query_temp("mj/xunluo"))
                return "����û��Ѳ�ߣ�Ҫ�һ�ӡ���";                  
        if(me->query_temp("mj/xunluo") < (i-1))
                return "��ȥ��ĵط��������Ȼ������Ѳ�������"; 
        if(me->query_temp("mj/xunluo") == 9)
                return "�ã����Ѿ�Ѳ�����ˡ�";    
        if(me->query_temp("mj/xunluo") >= i)
                return "������Ѿ�Ѳ�����ˣ���ȥ��ĵط������ɡ�";        
        if(me->query_temp("mj/attacker") && me->query_temp("mj/attacker") < 2)
                return "�ף����ǽ���ȥ������û�п��ɵ�������ô��ûȥ��";          

        command("nod "+me->query("id"));
        ob->set_temp("xl_waiting", 1);  
        call_out("restart", 15+random(30), me, ob);
        return " �ȵȣ����ҿ�����Ѳ�ߵ���ô���ˡ�\n";    
}

void restart(object me, object ob)
{     
        string arg;
        if(!ob) return;
        arg = ob->query("xl2");
        ob->delete_temp("xl_waiting");
        if(!me || !objectp(present(me, environment(ob)))){
               command("say Ү���Ǽһ���ô�����ˣ�");
               command("pat");
               return;
        }
        if(!living(me)){
               command("doubt "+me->query("id")); 
               return;
        }
        if(!me->query_temp(arg)){
               command("shake "+me->query("id")); 
               command("say �㻹��Щ�ط�û��Ѳ�ߵ��ɣ��Ȳ�æ��ӡ��"); 
               return;
        }
        if(random(3) == 1 && !me->query_temp("mj/attacker")){
               command("say �ţ��ո��е���������˵���󿴼��˲�����ݵ��ˣ��������ȥ������");          
               command("addoil "+me->query("id")); 
               me->set_temp("mj/attacker", 1);
               return;
        }
        me->delete_temp(arg);
        me->delete_temp("mj/attacker");
        me->add_temp("mj/xunluo", 1);
        command("thumb "+me->query("id")); 
        command("say �ã��������Ѿ�Ѳ������ˣ��Ҹ��㻭ӡ�ɡ�");
        return;
}

void setup()
{
	set("job_npc",1);
	::setup();
}
