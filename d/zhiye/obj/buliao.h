// buliao.h
// by augx@sj 10/22/2001

void create()
{
        set_name("��ƥ", ({ "buliao" }));
        set_weight(3000+random(5000));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ�Ĳ��ϡ�\n");
                set("value", 3000);
                set("buliao",1);
                set("no_sell",query("name")+"�����������������㻹���Լ����Ű�");// add by LinuX@SJ
        }
        setup();
        initlvl();
}

int query_level()
{
        return query("level");
}

int set_level(int i)
{       
        set("level",i);
        set("buliao",0);
        set("bu",1);        
        switch (i) {
                case 1:
                        set_name(HIW"�޻�"NOR, ({"mian hua","mianhua","hua"}));
                        set("long",HIW"����һ����ͨ�ޣ�������õ��������ϵ�ԭ�ϡ�\n"NOR);
                        set("material","mianhua");
                        set("value",500);
                        break;
                case 2:
                        set_name(YEL"����"NOR, ({"ya ma","yama","ma"}));
                        set("long",YEL"����һ�����飬������ľ�Ƥ��ά��֯���ɵĲ����ʵ������ָдֲڡ�\n"NOR);
                        set("material","yama");
                        set("value",800);
                        break;
                case 3:
                        set_name(YEL"����"NOR, ({"da ma","dama","ma"}));
                        set("long",YEL"����һ�����,ѡ�ô����ϸ��ά��֯���ɵ��Ĳ����������ϡ�\n"NOR);
                        set("material","dama");
                        set("value",1200);
                        break;
                case 4:
                        set_name(HIY"����"NOR, ({"zhu ma","zhuma","ma"}));
                        set("long",HIY"����һ���ϵȵ�����,ѡ���ϵȵ����龫֯���ɵĲ��ϣ�����ά����й��������ҿ�������\n"NOR);
                        set("material","zhuma");
                        set("value",1800);
                        break;
                case 5:
                        set_name(HIW"��˿"NOR, ({"cansi","si" }));
                        set("long",HIW"����Ѱ���Ҳ��µ�˿������ȥ��ϸ�Ử��\n"NOR);
                        set("material","cansi");
                        set("value",2500);
                        break;
                case 6:
                        set_name(HIY"ľ�޻�"NOR, ({"mumianhua","hua"}));
                        set("long",HIY"���е�ľ�޻���\n"NOR);
                        set("material","mumianhua");
                        set("value",3900);
                        break;
                case 7:
                        set_name(GRN"���˿"NOR, ({"yucansi","si"}));
                        set("long",GRN"���ǲ��԰ٶ��ȵ����˿������ȥ��һ���˿�Դ֣����м��ߵĵ��Լ������ԣ�ͨ��͸�ף��ǲ�˿�еľ�Ʒ��\n"NOR);
                        set("material","yucansi");
                        set("value",7000);
                        break;
                case 8:
                        set_name(HIW"����˿"NOR, ({"bingcansi","si"}));
                        set("long",HIW"��˵������ɽ��ĳ�ֱ����µ�˿��ճ�Լ�ǿ���������硣�����ýⷨ��һ��մ�������������类������\n"NOR);
                        set("material","bingcansi");
                        set("value",10000);
                        break;
                case 9:
                        set_name(WHT"���˿"NOR, ({"tiancansi","si"}));
                        set("long",WHT"������ɽ�������µ�˿�������ޱȣ�Ѱ���������ܽ���ն�ϡ�\n"NOR);
                        set("material","tiancansi");
                        set("value",20000);
                        break;
                case 10:
                	set_name(HIY"�����˿"NOR,({"longjiansi","si"}));
                	set("long",HIY"һ�����������Ķ�������֮˿��\n"NOR);
                	set("material","longcansi");
                	set("value",40000);
                	break;
                case 11:
                        set_name(MAG"��˹��˿"NOR, ({"bosi caisi","caisi","si"}));
                        set("long",MAG"����һ��ƥ������˹�����Ĳ�˹��˿��\n"NOR);
                        set("material","bosicaisi");
                        set("no_sell",1);
                        set("no_drop",1);
                        set("no_get",1);
                        set("no_give",1);
                        set("value",1);
                        set("job_buliao",1);
                        set_weight(1000+random(2000));
                        break;
                default:call_out("destroying", 1, this_object());
                 	return 0;     
        }
        set("value",query("value") * 40/10);
        WORKER_D->get_status(this_object(),1,query_level(),random(5)?1:0);
        //msg = WORKER_D->get_msg(query("material_prop"));
        //if(stringp(msg) && msg!="") set_temp("apply/long",({short()+"\n"+query("long")+msg}));
        return 1;
}

void change_state2(string type)
{
        if( query_level() != 11 ) return;

        set("buliao",0);
        set("bu",0);
        set("job_cloth",1);
        set("no_give",0);
        set("value",query("value") * 40/10);

        switch (type) {
                case "coat":
                        set_name(MAG"��˹����"NOR, ({"bosi caiyi","caiyi","bosi cai"}));
                        set("unit", "��");
                        break;
                case "armor":
                        set_name(MAG"��˹�ʼ�"NOR, ({"bosi caijia","caijia","bosi cai"}));
                        set("unit", "��");
                        break;
                case "boot":
                        set_name(MAG"��˹��ѥ"NOR, ({"bosi caixue","caixue","bosi cai"}));
                        set("unit", "˫");
                        break;
                case "belt":
                        set_name(MAG"��˹�ʴ�"NOR, ({"bosi caidai","caidai","bosi cai"}));
                        set("unit", "��");
                        break;
                case "cap":
                        set_name(MAG"��˹��ñ"NOR, ({"bosi caimao","caimao","bosi cai"}));
                        set("unit", "��");
                        break;
                case "mantle":
                        set_name(MAG"��˹����"NOR, ({"bosi pifeng","pifeng","bosi cai"}));
                        set("unit", "��");
                        break;
                case "glove":
                        set_name(MAG"��˹����"NOR, ({"bosi shoutao","shoutao","bosi cai"}));
                        set("unit", "˫");
                        break;
        }
        set("long",MAG"����һ"+query("unit")+"�ô�����˹�����Ĳ�˹�ʳ��Ƴɵ�"+name()+MAG"��\n"NOR);
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}

void change_name()
{
        switch (query_level()) {
                case 1:
                        set_name(HIW"�޲�"NOR, ({"mian bu","mianhua","bu"}));
                        set("long",HIW"����һ������ͨ��ɴ֯�ɵĲ���������õ��������ϡ�\n"NOR);
                        break;
                case 2:
                        set_name(YEL"���鲼"NOR, ({"yama bu","yama","bu"}));
                        set("long",YEL"����һ��������ľ�Ƥ��ά��֯���ɵĲ��ϣ��ʵ������ָдֲڡ�\n"NOR);
                        break;
                case 3:
                        set_name(YEL"���鲼"NOR, ({"dama bu","dama","bu"}));
                        set("long",YEL"����һ��ѡ�ô����ϸ��ά��֯���ɵ��Ĳ����������ϡ�\n"NOR);
                        break;
                case 4:
                        set_name(HIY"���鲼"NOR, ({"zhuma bu","zhuma","bu"}));
                        set("long",HIY"����һ��ѡ���ϵȵ����龫֯���ɵĲ��ϣ�����ά����й��������ҿ�������\n"NOR);
                        break;
                case 5:
                        set_name(HIW"˿��"NOR, ({"si chou","cansi","chou" }));
                        set("long",HIW"�߼۵�˿��\n"NOR);
                        break;
                case 6:
                        set_name(HIY"ľ�޲�"NOR, ({"mumian bu","mumianhua","bu"}));
                        set("long",HIY"���е�ľ�޲���\n"NOR);
                        break;
                case 7:
                        set_name(GRN"���˿��"NOR, ({"yucan sichou","yucansi","sichou"}));
                        set("long",GRN"���ǲ��԰ٶ��ȵ����˿�񡣿���ȥ��һ���˿�Դ֣����м��ߵĵ��Լ������ԣ�ͨ��͸�ף��ǲ�˿�еľ�Ʒ��\n"NOR);
                        break;
                case 8:
                        set_name(HIW"����˿��"NOR, ({"bingcan sichou","bingcansi","sichou"}));
                        set("long",HIW"���亱���ı���˿��\n"NOR);
                        break;
                case 9:
                        set_name(WHT"���˿��"NOR, ({"tiancan sichou","tiancansi","sichou"}));
                        set("long",WHT"������ɽ�������µ�˿�������ޱȣ�Ѱ���������ܽ���ն�ϡ�\n"NOR);
                        break;
                case 10:
                	set_name(HIY"����˿��"NOR,({"longjian sichou","longjiancansi","sichou"}));
                	set("long",HIY"һ�����������Ķ�������֮˿����˿��\n"NOR);
                	break;                
                case 11:
                        set_name(MAG"��˹�ʳ�"NOR, ({"bosi caichou","caichou","bosicansi","chou"}));
                        set("long",MAG"����һƥ������˹�����Ĳ�˹�ʳ�\n"NOR);
                        break;
        }
}
