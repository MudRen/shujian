// zhongzi.h
// by augx@sj 10/22/2001

void create()
{
        set_name("����", ({ "zhongzi" }));
        set_weight(100+random(500));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ӡ�\n");
                set("value", 300);
                set("zhongzi",1);
                set("canzi",0);
        }
        setup();
        initlvl();
}

int set_level(int i)
{
        switch (i) {
                case 1: 
                        set_name(HIW"�޻�����"NOR, ({"mianhua zhongzi","zhongzi","zi"}));
                        set("long",HIW"�޻������ӡ�\n"NOR);
                        set("material","mianhua");
                        set("value",100);
                        break;
                case 2: 
                        set_name(YEL"��������"NOR, ({"yama zhongzi","zhongzi","zi"}));
                        set("long",YEL"��������ӡ�\n"NOR);
                        set("material","yama");
                        set("value",160);
                        break;
                case 3: 
                        set_name(YEL"��������"NOR, ({"dama zhongzi","zhongzi","zi"}));
                        set("long",YEL"��������ӡ�\n"NOR);
                        set("material","dama");
                        set("value",240);
                        break;
                case 4: 
                        set_name(HIY"��������"NOR, ({"zhuma zhongzi","zhongzi","zi"}));
                        set("long",HIY"��������ӡ�\n"NOR);
                        set("material","zhuma");
                        set("value",360);
                        break;
                case 5: 
                        set_name(HIW"����"NOR, ({"can zi","zi" }));
                        set("long",HIW"�ϵ��ѡ�\n"NOR);
                        set("material","cansi");
                        set("value",500);
                        set("zhongzi",0);
                        set("canzi",1);
                        break;
                case 6: 
                        set_name(HIY"ľ������"NOR, ({"mumian zhongzi","zhongzi","zi"}));
                        set("long",HIY"ľ�޻������ӡ�\n"NOR);
                        set("material","mumianhua");
                        set("value",800);
                        break;
                        
                case 7: 
                        set_name(GRN"�����"NOR, ({"yucan zi","zi"}));
                        set("long",GRN"��ϵ��ѡ�\n"NOR);
                        set("material","yucansi");
                        set("value",1400);
                        set("zhongzi",0);
                        set("canzi",1);
                        break;
                case 8: 
                        set_name(HIW"������"NOR, ({"bingcan zi","zi"}));
                        set("long",HIW"���ϵ��ѡ�\n"NOR);
                        set("material","bingcansi");
                        set("value",2000);
                        set("zhongzi",0);
                        set("canzi",1);
                        break;
                case 9: 
                        set_name(WHT"�����"NOR, ({"tiancan zi","zi"}));
                        set("long",WHT"��ϵ��ѡ�\n"NOR);
                        set("material","tiancansi");
                        set("value",4000);
                        set("zhongzi",0);
                        set("canzi",1);
                        break;
                case 10:
                	set_name(HIY"�����"NOR,({"longcan zi","si"}));
                	set("long",HIY"һ�����������Ķ��ϵ��ѡ�\n"NOR);
                	set("material","longcansi");
                	set("value",8000);
                	set("zhongzi",0);
                        set("canzi",1);
                	break;
                 default:
			call_out("destroying", 1, this_object());
                 	return 0;     
        }
        set("level",i);
        return 1;
}

int query_level()
{
        return query("level");
}
void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}