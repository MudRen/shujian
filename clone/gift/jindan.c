// By action@SJ 
// 2009������ҽ�
#include <ansi.h>
#define JADE    "/d/zhiye/obj/othermaterial" //��
#define KUANGSHI    "/d/zhiye/obj/kuangshi" //��
#define BULIAO    "/d/zhiye/obj/buliao" //����
inherit SPEC;
void create()
{
        set_name(HIY"��"NOR, ({ "jindan"}) );
        set_weight(10);
                set("unit", "��");
                set("long", HIY"����������������������������������������������������������������������������������\n"NOR+
                	HIY"��"HBBLU+HIW"ţ������������ˣ������ص�ȥ����ӽҪ���Ľ𵰣����ǲ����ڡ�����52�С�������Ŷ��"NOR+HIY"��\n"NOR+
                	HIY"����������������������������������������������������������������������������������\n"NOR+
                	HIY"������"HBRED"�����ҽ𵰣������ϲ��ף��λ�齣��ң��´���죬��Դ������ţ���д��ˡ�"NOR+HIY"������\n"NOR+
                	HIY"����������������"HBGRN+HIW"����ȥ�Ұ�ľ�ȥ�ѽ��ҿ��ɣ�ȥľ����ʦ�����Ұɣ�"NOR+HIY"����������������\n"NOR+
                	HIY"������������������"HBGRN+HIW"���������Ķ���ľ������ʹ��(za)�����ҿ��𵰣�"NOR+HIY"������������������\n"NOR+
                	HIY"����������������������������������������������������������������������������������\n"NOR);
                set("value", 1500);
                set("unique", 1);
                set("material", "wood");
                set("no_drop", "�������صĶ�����ô������Ҷ��ء�\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set_weight(100);
                set("value",3000000);
                set("treasure",1);
                set("desc","������52�С��о��������Ľ𵰡�");
                set("credit",150);    

       setup();
}
void init()
{
        add_action("do_za", "za");
}

int do_za(string arg)
{        
       object ob, me = this_player();
       object obj,obnew,obj2;
       string str = "";
       int i = random(2);

       if(arg!="jindan")
          return notify_fail(HIR"������������������Ҫ�ҵ��ӻ������ǿյ�����\n"NOR);
                    
       if (!(ob = present("mu chui", me))) 
		      return notify_fail(HIR"û��ľ鳣���ô�����������ң�С����ӽ���֪������㣿\n"NOR);

       switch(i) {
                        case 0:         
                        	      obj = new (BULIAO);
                                obj->set_level(9+random(1));
                                obj->set_level(9+random(1));
                                break;                                
                        case 1:         
                                obj = new (KUANGSHI);
                                obj->set_level(9+random(1));
                                obj->set_level(9+random(1)); 
                                break;       
 
                        case 2:         
                                obj = new (JADE);
                                obj->set("secret_obj",1);
                                obj->set_level(5+random(1));
                                str = "��Ʒ";
                                str += "��"; 
                                break;        
                                break;                                                           
                        default:return 1;
                }
      	obj->move(this_player());

        message_vision(HIW"\n\n�����ľ鳳���"HIY"��"NOR+HIW"��ȥ��"HIY"��"NOR+HIW"��ʱ������ɢ����"HIR"��"HIM"��"HIG"��"HIC"��"NOR+HIW"�ġ�"HIR"��"HIB"â��"GRN"������������\n"NOR
                "\n" 
		"            "HIM"^��^^��^^��^^��^\^��^^��^^��^ "NOR"\n"+
		"          "HIR"(*^�n^*)"HIC"(*^�n^*)"HIG"(*^�n^*)"NOR"\n"+
		"         "HIB"�� "HIR"��"HIY"��"HIG"��"HIM"��"HIC"�S"HIR"��"HIM"��"HIB"��"HIY"��"HIB"��"MAG"��"HIB"�� \n"NOR+
		"                  "HIC"��"HIR"�"HIB"��"HIR"�"HIC"�� \n"+
		"                    "HIG"��"HIG"��     \n"+
		"                     "GRN"��     \n"NOR+
                "\n" NOR, me, ob);  
        CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HIM"��˵%s��"HIY"��"HIM"�л����һ"+obj->query("unit")+obj->name()+"��", me->name(1)));
        message_vision("$N��"HIY"��"NOR"�еõ���һ"+obj->query("unit")+obj->name()+"��\n\n",me); 
               
        destruct(this_object());
        return 1;               
}

