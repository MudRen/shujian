// corpse.c

#include <weapon.h>

inherit STICK;

int decayed;

void create()
{
        set_name("����ʬ��", ({ "corpse" }) );
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ʬ�塣\n");
                set("unit", "��" );
                set("wield_msg", "$N����$n׼��ս����\n");
                set("unwield_msg", "$N��$n���±��ڼ��ϡ�\n");
        }
        decayed = 0;
        if( clonep(this_object()) ) call_out("decay", 120, 1);
        init_stick(10);
        setup();
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
        decayed = phase;
        switch(phase) {
                case 1:
                        say( query("name") + "��ʼ�����ˣ�����һ�����ŵĶ����\n" );
                        delete_temp("apply");
                        switch(query("gender")) {
                                case "����":
                                        set_name("���õ���ʬ", ({ "corpse", "ʬ��" }) );
                                case "Ů��":
                                        set_name("���õ�Ůʬ", ({ "corpse", "ʬ��" }) );
                                default:
                                        set_name("���õ�ʬ��", ({ "corpse", "ʬ��" }) );
                        }
                        set("long",     "���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
                        call_out("decay", 120, phase + 1);
                        break;
                case 2:
                        say( query("name") + "���紵���ˣ����һ�ߺ��ǡ�\n" );
                        set_name("�ݸɵĺ���", ({ "skeleton" }) );
                        set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
                        call_out("decay", 60, phase + 1);
                        break;
                case 3:
                        say( "һ��紵������" + query("name") + "���ɹǻҴ�ɢ�ˡ�\n" );
                        if( environment() ) {
                                object *inv;
                                int i;
                                
                                inv = all_inventory(this_object());
                                for(i=0; i<sizeof(inv); i++) {
                                        if (!inv[i]->query("no_drop")
                                        && !inv[i]->query("no_get")
                                        && (inv[i]->query("value") || inv[i]->value()))
                                                inv[i]->move(environment());
                                }
                        }
                        destruct(this_object());
                        break;
        }
}

