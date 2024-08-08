#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materias[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &src);
        MateriaSource &operator=(const MateriaSource &original);
        ~MateriaSource();

        void learnMateria(AMateria* materia);
        AMateria* createMateria(std::string const & type);
};

#endif
